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
// Created by tete on 06/22/2025.
//
#pragma once

#ifndef CSODEFS_H
#define CSODEFS_H
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <libcso/libcso_config.h>

#ifdef __cplusplus
#define CSO_CPP_COMPAT_START extern "C" {
#define CSO_CPP_COMPAT_END }
#else
#define CSO_CPP_COMPAT_START
#define CSO_CPP_COMPAT_END
#endif

CSO_CPP_COMPAT_START

#if !defined(CSO_PUB_API_OPEN)
#   ifndef CSO_CONFIG_STATIC_ONLY
#       ifdef __unix
#           define CSO_PUB_API_OPEN __attribute__((visibility("default")))
#       elif defined(_WIN32)
#           define CSO_PUB_API_OPEN
/*#           ifdef BUILDING_CSO
#               define CSO_PUB_API_OPEN __declspec(dllexport)
#           else
#               define CSO_PUB_API_OPEN __declspec(dllimport)
#           endif*/
#       endif
#   else
#       define CSO_PUB_API_OPEN
#   endif
#endif


#ifndef CSO_DEPRECATED
#   define CSO_DEPRECATED __attribute__ ((deprecated))
#endif
#ifndef CSO_MSG_DEPRECATED
#   define CSO_MSG_DEPRECATED(msg) __attribute__ ((deprecated(msg)))
#endif
#ifndef CSO_FORCE_INLINE
#   define CSO_FORCE_INLINE __attribute__((always_inline)) static __inline
#endif
#ifndef CSO_VERY_VOLATILE
#   define CSO_VERY_VOLATILE __attribute__((optimize("O0")))
#endif
#ifndef CSO_VERY_OPTIMIZED
#   define CSO_VERY_OPTIMIZED __attribute__((optimize("O3")))
#endif

#if defined(CSO_NO_STD_BOOL) || !__has_include("stdbool.h")
typedef enum
{
    false
    true
} cso_bool;
typedef uint8_t cso_flag;
#else
#   include <stdbool.h>
typedef bool cso_bool;
typedef bool cso_flag;
#endif

typedef uint8_t cso_byte;

typedef const char* cso_thin_rtti_class_id_t;

CSO_PUB_API_OPEN void* cso_plat_malloc(size_t size);
CSO_PUB_API_OPEN void* cso_plat_realloc(void* ptr, size_t new_size);
CSO_PUB_API_OPEN void* cso_plat_calloc(size_t num, size_t size);
CSO_PUB_API_OPEN void  cso_plat_free(void* ptr);

/**
 * @brief Turns a class type name into a string for the thin pseudo rtti system
 * @param type The class type to check against (use the *_c type).
 */
#define cso_toTypeNameStr(type) #type

/**
 * @brief A blind cast to an object type within the inheritance chain
 * @param type The class type to check against (use the *_c type).
 * @param obj A valid object instance (must not be NULL).
 * @note This does not verify the cast at runtime—use only when you're sure of the object's type.
 *       Unless you can determine it with cso_instanceof
 */
#define cso_super_cast(type, obj) ((type)obj)

/**
 * @brief Simple helper macro for setting up inheritance in a class
 * @param type The class type to check against (use the *_t type).
 */
#define cso_class_extends(type) type super

#define CSO_UNUSED(x) ((void)(x))

CSO_CPP_COMPAT_END

#endif //CSODEFS_H