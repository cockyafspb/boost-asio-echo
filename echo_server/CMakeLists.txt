cmake_minimum_required(VERSION 3.26)
project(echo_server)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include_directories(echo_server "C:\\boost\\boost_1_82_0")
add_executable(echo_server main.cpp server.cpp session.cpp)

if (WIN32)
    set(libs ws2_32 wsock32)
    target_link_libraries(echo_server ${libs})
endif()