cmake_minimum_required(VERSION 3.9)

project(http-server-asio)

if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(test)
endif()

set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} src/HttpServerAsio.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
  interface  
)
target_link_libraries(${PROJECT_NAME} http-server cpp-netlib)
