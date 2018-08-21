cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "main")
project(${PROJECT_NAME})

set(SOURCE_FILES
	main_lib.h
	main_lib.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME}_lib PUBLIC sub_lib_a
                                                 sub_lib_b)
											
install (FILES "main_lib.h" DESTINATION include)


add_library(${PROJECT_NAME}_lib_comp STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}_lib_comp PRIVATE sub_lib_a
                                                       sub_lib_b)

install(TARGETS ${PROJECT_NAME}_lib_comp DESTINATION lib)


## collect dependent libraries into a directory
set(DEPENDENT_LIB_DIR "${PROJECT_BINARY_DIR}/temp_libs")

list(APPEND commands COMMAND echo collect dependent libs)

## clean and recreate temp directory
list(APPEND commands COMMAND ${CMAKE_COMMAND} -E remove_directory ${DEPENDENT_LIB_DIR})
list(APPEND commands COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENT_LIB_DIR})

## copy referenced libraries
list(APPEND commands COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sub_lib_a> ${DEPENDENT_LIB_DIR})
list(APPEND commands COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sub_lib_b> ${DEPENDENT_LIB_DIR})

list(APPEND commands COMMAND echo done)

add_custom_command(TARGET ${PROJECT_NAME}_lib_comp PRE_BUILD ${commands})

set_target_properties(${PROJECT_NAME}_lib_comp PROPERTIES STATIC_LIBRARY_FLAGS_DEBUG "${DEPENDENT_LIB_DIR}/*.lib")
											 
