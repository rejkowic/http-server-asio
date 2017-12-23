cmake_minimum_required(VERSION 3.9)

project(http-server-asio-test)

add_subdirectory(app-factory)
add_subdirectory(http-server)
add_subdirectory(cpp-netlib)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} app-factory http-server-asio cpp-netlib)
