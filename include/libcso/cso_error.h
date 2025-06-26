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
#pragma once

#ifndef CSO_ERROR_H
#define CSO_ERROR_H
#include <errno.h>
#include <libcso/csodefs.h>

CSO_CPP_COMPAT_START

#define CSO_ERR_DOMAIN_RUNTIME "RuntimeError"
#define CSO_ERR_DOMAIN_IO      "IOError"

typedef struct cso_error_s
{
    const char* error_type; // e.g., "InvalidArgument"
    const char* message;
    int code;
    void* data;
} cso_error_t;

typedef cso_error_t *cso_error_o;

CSO_PUB_API_OPEN
cso_error_o cso_error_new(const char* type, const char* message, int code, void* data);

CSO_PUB_API_OPEN
void cso_error_destroy(cso_error_o self);

CSO_PUB_API_OPEN
void cso_set_last_error(cso_error_o err);

CSO_PUB_API_OPEN
cso_error_o cso_get_last_error();

CSO_PUB_API_OPEN
void cso_clear_last_error();

static __inline cso_error_o cso_error_from_errno()
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

static __inline void cso_throw_runtime(const char* msg, int code, void* data)
{
    cso_set_last_error(cso_error_new("RuntimeError", msg, code, data));
}

static __inline cso_bool cso_error_happened()
{
    return cso_get_last_error() != NULL;
}

#define CSO_RUNTIME_FAIL(msg, code, ...) \
do \
{ \
    cso_set_last_error(cso_error_new(CSO_ERR_DOMAIN_RUNTIME, msg, code, NULL)); \
    return __VA_ARGS__; \
} while (0)

CSO_CPP_COMPAT_END

#endif
