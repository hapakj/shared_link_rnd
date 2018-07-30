cmake_minimum_required(VERSION 3.5)
project("shared_link_rnd")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

if (INLINED)
    add_definitions("-DINLINED=1")
endif()


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib_a)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib_b)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib_c)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sample)

