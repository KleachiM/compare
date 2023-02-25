cmake_minimum_required(VERSION 3.24)
project(compare)

set(CMAKE_CXX_STANDARD 17)

add_executable(compare main.cpp)

add_custom_command(TARGET compare
        POST_BUILD
        COMMAND /bin/sh ${CMAKE_CURRENT_SOURCE_DIR}/test/tst.sh
        )
