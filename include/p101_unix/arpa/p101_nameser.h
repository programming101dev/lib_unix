#ifndef LIBP101_UTIL_ARPA_P101_NAMESER_H
#define LIBP101_UTIL_ARPA_P101_NAMESER_H

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

#include <arpa/nameser.h>
#include <p101_env/env.h>
#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int      p101_ns_msg_getflag(const struct p101_env *env, struct p101_error *err, ns_msg handle, int flag);
    uint16_t p101_ns_get16(const struct p101_env *env, struct p101_error *err, const unsigned char *src);
    uint32_t p101_ns_get32(const struct p101_env *env, struct p101_error *err, const unsigned char *src);
    void     p101_ns_put16(const struct p101_env *env, struct p101_error *err, unsigned int src, unsigned char *dst);
    void     p101_ns_put32(const struct p101_env *env, struct p101_error *err, unsigned long src, unsigned char *dst);
    int      p101_ns_initparse(const struct p101_env *env, struct p101_error *err, const unsigned char *msg, int msglen, ns_msg *handle);
    int      p101_ns_skiprr(const struct p101_env *env, struct p101_error *err, const unsigned char *ptr, const unsigned char *eom, ns_sect section, int count);
    int      p101_ns_parserr(const struct p101_env *env, struct p101_error *err, ns_msg *handle, ns_sect section, int rrnum, ns_rr *rr);
    int      p101_ns_name_ntol(const struct p101_env *env, struct p101_error *err, const unsigned char *src, unsigned char *dst, size_t dstsiz);
    int      p101_ns_name_ntop(const struct p101_env *env, struct p101_error *err, const unsigned char *src, char *dst, size_t dstsiz);
    int      p101_ns_name_pton(const struct p101_env *env, struct p101_error *err, const char *src, unsigned char *dst, size_t dstsiz);
    int      p101_ns_name_unpack(const struct p101_env *env, struct p101_error *err, const unsigned char *msg, const unsigned char *eom, const unsigned char *src, unsigned char *dst, size_t dstsiz);
    int      p101_ns_name_pack(const struct p101_env *env, struct p101_error *err, const unsigned char *src, unsigned char *dst, int dstsiz, const unsigned char **dnptrs, const unsigned char **lastdnptr);
    int      p101_ns_name_uncompress(const struct p101_env *env, struct p101_error *err, const unsigned char *msg, const unsigned char *eom, const unsigned char *src, char *dst, size_t dstsiz);
    int      p101_ns_name_compress(const struct p101_env *env, struct p101_error *err, const char *src, unsigned char *dst, size_t dstsiz, const unsigned char **dnptrs, const unsigned char **lastdnptr);
    int      p101_ns_name_skip(const struct p101_env *env, struct p101_error *err, const unsigned char **ptrptr, const unsigned char *eom);
    void     p101_ns_name_rollback(const struct p101_env *env, struct p101_error *err, const unsigned char *src, const unsigned char **dnptrs, const unsigned char **lastdnptr);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_ARPA_P101_NAMESER_H
