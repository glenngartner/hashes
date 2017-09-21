cmake_minimum_required(VERSION 3.8)
project(hashes)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE_FILES src/main.cpp src/core.cpp include/core.h src/hash.cpp include/hash.h src/deepHash.cpp src/deepHash.h src/linkedListItem.cpp include/linkedListItem.h)
add_executable(hashes ${SOURCE_FILES})