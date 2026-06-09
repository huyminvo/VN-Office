/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef ASSOCIATION_H
#define ASSOCIATION_H


class Association
{
public:
    Association(const Association&) = delete;
    Association& operator=(const Association&) = delete;
    static Association& instance();

    void chekForAssociations(int uid);    

private:
    Association();
    ~Association();

    class AssociationPrivate;
    AssociationPrivate *pimpl;
};

#endif // ASSOCIATION_H
