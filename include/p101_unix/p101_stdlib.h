#ifndef LIBP101_UTIL_P101_STDLIB_H
#define LIBP101_UTIL_P101_STDLIB_H

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
#include <p101_env/env.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    uint32_t p101_arc4random(const struct p101_env *env);
    void     p101_arc4random_buf(const struct p101_env *env, void *buf, size_t nbytes);
    uint32_t p101_arc4random_uniform(const struct p101_env *env, uint32_t upper_bound);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_STDLIB_H
