#ifndef LIBP101_UTIL_P101_FSTAB_H
#define LIBP101_UTIL_P101_FSTAB_H

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

#include <fstab.h>
#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct fstab *p101_getfsent(const struct p101_env *env, struct p101_error *err);
    struct fstab *p101_getfsspec(const struct p101_env *env, struct p101_error *err, const char *spec);
    struct fstab *p101_getfsfile(const struct p101_env *env, struct p101_error *err, const char *file);
    int           p101_setfsent(const struct p101_env *env, struct p101_error *err);
    void          p101_endfsent(const struct p101_env *env, struct p101_error *err);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_FSTAB_H
