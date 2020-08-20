cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(normal_distributions_transform)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

message(${PCL_INCLUDE_DIRS})


add_executable(normal_distributions_transform main.cpp)
target_link_libraries (normal_distributions_transform ${PCL_LIBRARIES})