#ifndef LIBP101_UTIL_P101_IFADDRS_H
#define LIBP101_UTIL_P101_IFADDRS_H

/*
 * Copyright 2022-2024 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ifaddrs.h>
#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int  p101_getifaddrs(const struct p101_env *env, struct p101_error *err, struct ifaddrs **ifap);
    void p101_freeifaddrs(const struct p101_env *env, struct ifaddrs *ifp);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_IFADDRS_H
