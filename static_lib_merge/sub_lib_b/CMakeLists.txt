cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "sub_lib_b")
project(${PROJECT_NAME})

set(SOURCE_FILES
	sub_lib_b.h
	sub_lib_b.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

install (FILES "sub_lib_b.h" DESTINATION include)

