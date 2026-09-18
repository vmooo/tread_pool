cmake_minimum_required(VERSION 3.31)
project(tread_pool LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC_FILES "src/*.c")

add_library(tread_pool ${SRC_FILES})

target_include_directories(tread_pool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_FILES "tests/*.cpp")

add_executable(run_tests ${TEST_FILES})

target_compile_options(run_tests PRIVATE -Wall -Wextra -Wunused-result -O2 -pthread)

target_link_libraries(run_tests
        PRIVATE
        tread_pool
        gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(run_tests)

