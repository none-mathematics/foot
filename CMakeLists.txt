##
## Copyright (c) 2023 none-mathematics
## Use of this source code is governed by a MIT-style
## license that can be found in the LICENSE file.
##
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(foot LANGUAGES CXX VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_executable(main foot.cpp foot.h)
