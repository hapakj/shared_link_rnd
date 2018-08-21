cmake_minimum_required(VERSION 3.5)
project("shared_link_rnd")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sub_lib_a)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sub_lib_b)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/main_lib)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sample)

