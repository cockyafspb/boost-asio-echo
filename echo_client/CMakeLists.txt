cmake_minimum_required(VERSION 3.26)
project(echo_client)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include_directories(echo_server "C:\\boost\\boost_1_82_0")
add_executable(echo_client main.cpp client.cpp)

if (WIN32)
    set(libs ws2_32 wsock32)
    target_link_libraries(echo_client ${libs})
endif()