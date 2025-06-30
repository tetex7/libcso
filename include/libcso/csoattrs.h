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

/*
 * No this is not some form of crazy system for class attributes
 * This is actual attributes for the compiler(Preferably gcc)
 */
#pragma once

#ifndef CSOATTR_H
#define CSOATTR_H
#include <libcso/libcso_config.h>

#if !defined(CSO_PUB_API_OPEN)
#   ifndef CSO_CONFIG_STATIC_ONLY
#       ifdef __unix
#           define CSO_PUB_API_OPEN __attribute__((visibility("default")))
#       elif defined(_WIN32)
#           define CSO_PUB_API_OPEN
// I hate buildings shared libraries for windows
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
#   define CSO_MSG_DEPRECATED(msg) __attribute__((deprecated(msg)))
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
#ifndef CSO_NO_IMPLICIT_PADDING
#   define CSO_NO_IMPLICIT_PADDING __attribute__((packed))
#endif



#endif //CSOATTR_H
