cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "lib_c")
project(${PROJECT_NAME})

set(SOURCE_FILES
	lib_c.h
	lib_c.cpp
)

add_library(${PROJECT_NAME} ${LIB_TYPE} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC lib_a)

