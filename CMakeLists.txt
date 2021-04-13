cmake_minimum_required(VERSION 3.17)
project(sdltest)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_PATH "C:\\vclib")
find_package(SDL2 REQUIRED)
include_directories()

set(SDL2_IMAGE_PATH "C:\\vclib\\SDL2_image")
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(game Game.cpp)
add_executable(sdltest main.cpp Game.cpp TextureManager.cpp)

target_link_libraries(sdltest ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})