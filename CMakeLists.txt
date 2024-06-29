cmake_minimum_required(VERSION 3.28)
project(Symulator_banku)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(Symulator_banku main.cpp)
target_link_libraries(Symulator_banku fmt)