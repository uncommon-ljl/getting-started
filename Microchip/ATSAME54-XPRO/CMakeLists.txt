# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)
project(atsame54_azure_iot C ASM)

set(CMAKE_C_STANDARD 99)
set(GSG_BASE_DIR ${PROJECT_SOURCE_DIR}/../..)

list(APPEND CMAKE_MODULE_PATH ${GSG_BASE_DIR}/cmake)

include(utilities)

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

add_subdirectory(lib)
add_subdirectory(app)
