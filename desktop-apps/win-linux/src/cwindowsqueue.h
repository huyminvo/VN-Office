/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CWINDOWSQUEUE_H
#define CWINDOWSQUEUE_H

#include <algorithm>
#include <functional>
#include <thread>
#include <mutex>
#include <utility>
#include <vector>
#include <atomic>


#define THREAD_WAIT_INTERVAL 10

template<typename T>
class CWindowsQueue
{
    std::vector<std::thread> m_threads;
    std::mutex m_mutex;
    std::vector<T> m_wintoclose;
    std::atomic_bool m_queueCanceled{false};

    std::function<void(T)> m_callback;
public:
    CWindowsQueue()
    {}

    ~CWindowsQueue()
    {
        for (std::thread& t: m_threads)
        {
            if ( t.joinable() )
                t.join();
        }
    }

    void start_queue() {
        if ( !m_wintoclose.empty() ) {
            trigger_callback(*m_wintoclose.begin());
        }
    }

    void enter(const T& iter)
    {
        m_wintoclose.push_back(iter);
        if ( !(m_wintoclose.size() > 1) ) {
            m_queueCanceled.store(false);

            std::function<void()> start_func_(std::bind(&CWindowsQueue::start_queue, this));

            std::thread([start_func_]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(THREAD_WAIT_INTERVAL));
                start_func_();
            }).detach();
        }
    }

    void leave(T iter)
    {
        m_threads.push_back(std::thread(&CWindowsQueue::leave_thread_func, this, iter));
    }

    void cancel()
    {
        m_threads.push_back(std::thread(&CWindowsQueue::cancel_thread_func, this));
    }

    void setcallback(std::function<void(T)>& fn)
    {
        m_callback = fn;
    }


private:
    void leave_thread_func(T iter)
    {
        std::lock_guard<std::mutex> lock{m_mutex};

        const auto& it = std::find_if(m_wintoclose.begin(), m_wintoclose.end(), [&](T i){ return i == iter; });

        if ( it != m_wintoclose.end() )
            m_wintoclose.erase(it);

        if ( !m_wintoclose.empty() && !m_queueCanceled.load() ) {
            trigger_callback(*m_wintoclose.begin());
        }
    }

    void cancel_thread_func()
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_wintoclose.clear();
        m_queueCanceled.store(true);
    }

    void trigger_callback(const T& iter)
    {
        if ( m_callback )
            m_callback(iter);
    }
};

#endif // CWINDOWSQUEUE_H
