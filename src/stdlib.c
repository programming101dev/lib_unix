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

#include "p101_unix/p101_stdlib.h"
#include <stdlib.h>
#ifdef __has_include
    #if __has_include("bsd/stdlib.h")
        #include <bsd/stdlib.h>
    #endif
#endif
uint32_t p101_arc4random(const struct p101_env *env)
{
    uint32_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = arc4random();

    return ret_val;
}

void p101_arc4random_buf(const struct p101_env *env, void *buf, size_t nbytes)
{
    P101_TRACE(env);
    errno = 0;
    arc4random_buf(buf, nbytes);
}

uint32_t p101_arc4random_uniform(const struct p101_env *env, uint32_t upper_bound)
{
    uint32_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = arc4random_uniform(upper_bound);

    return ret_val;
}
