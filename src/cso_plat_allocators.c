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


#include "libcso/csodefs.h"

#ifdef CSO_CONFIG_USE_LIB_SAFENET
#   include <libsafetynet.h>
#else
#   include <stdlib.h>
#endif

CSO_PUB_API_OPEN
void* cso_plat_malloc(size_t size)
{
#ifdef CSO_CONFIG_USE_LIB_SAFENET
    return sn_malloc(size);
#else
    return malloc(size);
#endif
}

CSO_PUB_API_OPEN
void* cso_plat_realloc(void* ptr, size_t new_size)
{
#ifdef CSO_CONFIG_USE_LIB_SAFENET
    return sn_realloc(ptr, new_size);
#else
    return realloc(ptr, new_size);
#endif
}

CSO_PUB_API_OPEN
void* cso_plat_calloc(size_t num, size_t size)
{
#ifdef CSO_CONFIG_USE_LIB_SAFENET
    return sn_calloc(num, size);
#else
    return calloc(num, size);
#endif
}

CSO_PUB_API_OPEN
void cso_plat_free(void* ptr)
{
#ifdef CSO_CONFIG_USE_LIB_SAFENET
    sn_free(ptr);
#else
    free(ptr);
#endif
}
