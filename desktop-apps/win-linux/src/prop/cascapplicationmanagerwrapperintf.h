/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CASCAPPLICATIONMANAGERWRAPPER_P_H
#define CASCAPPLICATIONMANAGERWRAPPER_P_H

#include "cascapplicationmanagerwrapper.h"
#include "cascapplicationmanagerwrapper_private.h"

CAscApplicationManagerWrapper::CAscApplicationManagerWrapper()
    : CAscApplicationManagerWrapper(new CAscApplicationManagerWrapper_Private(this))
{
}


#endif // CASCAPPLICATIONMANAGERWRAPPER_PRIVATE_H
