#ifndef LIBP101_UTIL_P101_TTYENT_H
#define LIBP101_UTIL_P101_TTYENT_H

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

#include <p101_env/env.h>
#include <ttyent.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct ttyent *p101_getttyent(const struct p101_env *env, struct p101_error *err);
    struct ttyent *p101_getttynam(const struct p101_env *env, struct p101_error *err, const char *name);
    int            p101_setttyent(const struct p101_env *env, struct p101_error *err);
    int            p101_endttyent(const struct p101_env *env, struct p101_error *err);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_TTYENT_H
