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
// Created by tete on 06/30/2025.
//
#pragma once

#ifndef CSOBOOL_H
#define CSOBOOL_H
#include <stdint.h>
#include <libcso/cso_cpp_compat.h>

#ifdef __has_include
#   if __has_include("stdbool.h")
#       define CSO_FANCY_HAS_BOOL_CHECK 1
#   else
#       define CSO_FANCY_HAS_BOOL_CHECK 0
#   endif
#else
#   warning "Compiler appears to not support __has_include Defaulting to CSO_FANCY_HAS_BOOL_CHECK to 0"
#   define CSO_FANCY_HAS_BOOL_CHECK 0
#endif


#if (defined(CSO_NO_STD_BOOL) || !CSO_FANCY_HAS_BOOL_CHECK) && !defined(CSO_CPP_COMPAT_MODE)
#   ifndef true
#       define true 1
#   endif
#   ifndef false
#       define false 0
#   endif
typedef uint8_t cso_bool;
#else
#   ifndef CSO_CPP_COMPAT_MODE
#       include <stdbool.h>
#   endif
typedef bool cso_bool;
#endif

/**
 * @brief a bool that should not be set with a true/false literal but with a binary value(0/1)
 */
typedef cso_bool cso_flag;

#endif //CSOBOOL_H
