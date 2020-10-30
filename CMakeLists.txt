cmake_minimum_required(VERSION 3.17)
project(cropImage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(OpenCV_FOUND 1)
find_package( OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)

add_executable(cropImage ${SOURCE_FILES})

target_link_libraries(cropImage ${OpenCV_LIBS})