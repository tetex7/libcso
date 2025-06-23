#
# Copyright (C) 2024  Tetex7
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.16)

include(BuildOptions.cmake)

project(cso VERSION ${CSO_CONFIG_STR_VERSION} LANGUAGES C)

#enable_testing()

set(CMAKE_SKIP_INSTALL_RULES ON)

# Set output directory
set(BIN_DIR ${CMAKE_BINARY_DIR}/build)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

#file(GLOB C_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.c")
#file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.c")
#add_executable(safetynet_tests ${TEST_SOURCES})
#target_include_directories(safetynet_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
#target_link_libraries(safetynet_tests safetynet_static)

# Enable position-independent code (like -fPIC)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)



# Compiler flags
if (CSO_CONFIG_DEBUG)
    set(DEBUG_FLAGS "-g -O0")
else()
    set(DEBUG_FLAGS "-g -O1")
endif()

if(CSO_CONFIG_STR_VERSION)
    set(VER_FLAG_S "${SN_CONFIG_STR_VERSION}")
else()
    set(VER_FLAG_S "dev")
endif()

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/libcso_config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/include/libcso/libcso_config.h
)

# Common flags
set(GCC_FLAGS
    "${DEBUG_FLAGS} -Wall -Werror -fno-strict-aliasing -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function"

)

if (NOT CSO_CONFIG_STATIC_ONLY)
set(GCC_FLAGS "${GCC_FLAGS} -fvisibility=hidden")
endif ()

# Set C and C++ flags
set(CMAKE_C_FLAGS "${GCC_FLAGS} -std=c99 -D__SN_WIP_CALLS__=")
#set(CMAKE_CXX_FLAGS "${GCC_FLAGS} -std=gnu++17")

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Collect source files
file(GLOB C_SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/**/*.c")
#file(GLOB CXX_SOURCES "${SRC_DIR}/*.cpp")

if (NOT WIN32 OR NOT CSO_CONFIG_STATIC_ONLY)
# Shared library
add_library(cso_shared SHARED ${C_SOURCES})
set_target_properties(cso_shared PROPERTIES
    OUTPUT_NAME "cso"
    LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
)
target_compile_definitions(cso_shared PRIVATE BUILDING_CSO)
endif ()

if (CSO_CONFIG_STATIC_ONLY OR WIN32)
# Static library
add_library(cso_static STATIC ${C_SOURCES})
set_target_properties(cso_static PROPERTIES
    OUTPUT_NAME "cso"
    ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}
)

add_custom_command(TARGET cso_static POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -S --keep-symbols=${CMAKE_CURRENT_SOURCE_DIR}/public.sym $<TARGET_FILE:cso_static> $<TARGET_FILE:cso_static>
        COMMENT "Stripping static library symbols with objcopy"
)

endif()
