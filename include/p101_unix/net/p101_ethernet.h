#ifndef LIBP101_UTIL_NET_P101_ETHERNET_H
#define LIBP101_UTIL_NET_P101_ETHERNET_H

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

#include <inttypes.h>
#include <sys/types.h>
#include <net/ethernet.h>
#include <p101_env/env.h>
#include <sys/socket.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct ether_addr *p101_ether_aton(const struct p101_env *env, struct p101_error *err, const char *asc);
    int                p101_ether_hostton(const struct p101_env *env, struct p101_error *err, const char *hostname, struct ether_addr *addr);
    int                p101_ether_line(const struct p101_env *env, struct p101_error *err, const char *line, struct ether_addr *addr, char *hostname);
    char              *p101_ether_ntoa(const struct p101_env *env, struct p101_error *err, const struct ether_addr *addr);
    int                p101_ether_ntohost(const struct p101_env *env, struct p101_error *err, char *hostname, const struct ether_addr *addr);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_NET_P101_ETHERNET_H
