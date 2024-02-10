#ifndef LIBP101_UTIL_P101_RESOLV_H
#define LIBP101_UTIL_P101_RESOLV_H

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

#include <netinet/in.h>
#include <p101_env/env.h>
#include <resolv.h>
#include <sys/socket.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int  p101_res_hnok(const struct p101_env *env, struct p101_error *err, const char *dn);
    int  p101_res_ownok(const struct p101_env *env, struct p101_error *err, const char *dn);
    int  p101_res_mailok(const struct p101_env *env, struct p101_error *err, const char *dn);
    int  p101_res_dnok(const struct p101_env *env, struct p101_error *err, const char *dn);
    int  p101_b64_ntop(const struct p101_env *env, struct p101_error *err, unsigned char *src, size_t srclength, char *target, size_t target_size);
    int  p101_b64_pton(const struct p101_env *env, struct p101_error *err, const char *src, unsigned char *dst, size_t dstsiz);
    int  p101_dn_skipname(const struct p101_env *env, struct p101_error *err, const unsigned char *comp_dn, const unsigned char *eom);
    int  p101_dn_comp(const struct p101_env *env, struct p101_error *err, const char *exp_dn, unsigned char *comp_dn, int length, unsigned char **dnptrs, unsigned char **lastdnptr);
    int  p101_dn_expand(const struct p101_env *env, struct p101_error *err, const unsigned char *msg, const unsigned char *eomorig, const unsigned char *comp_dn, char *exp_dn, int length);
    int  p101_res_ninit(const struct p101_env *env, struct p101_error *err, res_state statep);
    int  p101_res_nquery(const struct p101_env *env, struct p101_error *err, res_state statep, const char *dname, int cls, int type, unsigned char *answer, int anslen);
    int  p101_res_nsearch(const struct p101_env *env, struct p101_error *err, res_state statep, const char *dname, int cls, int type, unsigned char *answer, int anslen);
    int  p101_res_nquerydomain(const struct p101_env *env, struct p101_error *err, res_state statep, const char *name, const char *domain, int cls, int type, unsigned char *answer, int anslen);
    int  p101_res_nmkquery(const struct p101_env *env, struct p101_error *err, res_state statep, int op, const char *dname, int cls, int type, const unsigned char *data, int datalen, const unsigned char *newrr, unsigned char *buf, int buflen);
    int  p101_res_nsend(const struct p101_env *env, struct p101_error *err, res_state statep, const unsigned char *msg, int msglen, unsigned char *answer, int anslen);
    void p101_res_nclose(const struct p101_env *env, struct p101_error *err, res_state statep);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UTIL_P101_RESOLV_H
