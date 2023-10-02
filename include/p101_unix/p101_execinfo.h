#ifndef LIBP101_UTIL_P101_EXECINFO_H
#define LIBP101_UTIL_P101_EXECINFO_H

/*
 * Copyright 2022-2022 D'Arcy Smith.
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

#include <execinfo.h>
#include <p101_env/env.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // TODO this is not the same on FreeBSD
//    size_t p101_backtrace(const struct p101_env *env, struct p101_error *err, void **addrlist, size_t len);
//    char **p101_backtrace_symbols(const struct p101_env *env, struct p101_error *err, void *const *addrlist, size_t len);
//    int    p101_backtrace_symbols_fd(const struct p101_env *env, struct p101_error *err, void *const *addrlist, size_t len, int fd);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_EXECINFO_H
