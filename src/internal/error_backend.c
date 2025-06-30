/*
 * Copyright (C) 2025  Tetex7
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

//
// Created by tete on 06/23/2025.
//

#include "libcso/cso_error.h"
#include <string.h>

#ifdef CSO_CONFIG_THREAD_AWARE
static __thread cso_error_o __cso_last_error = NULL; // NOLINT(*-reserved-identifier)
#else
static cso_error_o __cso_last_error = NULL; // NOLINT(*-reserved-identifier)
#endif


CSO_PUB_API_OPEN
cso_error_o cso_error_new(const char* type, const char* message, int code, void* data)
{
    cso_error_o self = cso_plat_malloc(sizeof(cso_error_t));
    if (!self) return NULL;
    memset(self, 0, sizeof(cso_error_t));

    self->error_type = type;
    self->message = message;
    self->code = code;
    self->data = data;

    return self;
}

CSO_PUB_API_OPEN
void cso_error_destroy(cso_error_o self)
{
    if (!self) return;
    cso_plat_free(self);
}

CSO_PUB_API_OPEN
void cso_set_last_error(cso_error_o err)
{
    if (__cso_last_error) cso_error_destroy(__cso_last_error); // optional auto-free
    __cso_last_error = err;
}

CSO_PUB_API_OPEN
cso_error_o cso_get_last_error()
{
    return __cso_last_error;
}

CSO_PUB_API_OPEN
void cso_clear_last_error()
{
    if (__cso_last_error)
    {
        cso_error_destroy(__cso_last_error);
        __cso_last_error = NULL;
    }
}

CSO_PUB_API_OPEN
cso_error_o cso_error_from_errno()
{
    const char* err_msg = strerror(errno);
    if (!err_msg) err_msg = "Unknown system error";
    return cso_error_new(
        "SystemError",
        err_msg,
        errno,
        NULL
    );
}

__attribute__((destructor))
void exit_error_cleanup()
{
    if (!__cso_last_error)
        cso_error_destroy(__cso_last_error);
}
