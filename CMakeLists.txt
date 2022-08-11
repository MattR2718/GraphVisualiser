cmake_minimum_required(VERSION 3.0.0)
project(GraphVisualiser VERSION 0.1.0)

# SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_BUILD_TYPE Debug)

list(APPEND CMAKE_PREFIX_PATH "C:\\Users\\matth\\vcpkg\\installed\\x86-windows\\share\\sfml")
find_package(SFML CONFIG REQUIRED COMPONENTS graphics system window)
include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)