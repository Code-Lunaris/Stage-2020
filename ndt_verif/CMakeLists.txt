cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(MY_GRAND_PROJECT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# add_executable(vizu_verif vizu_verif.cpp)
# target_link_libraries(vizu_verif ${PCL_LIBRARIES})

add_executable(error_verif error_verif.cpp)
target_link_libraries(error_verif ${PCL_LIBRARIES})