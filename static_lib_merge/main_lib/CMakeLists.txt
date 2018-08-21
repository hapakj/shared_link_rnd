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

cmake_policy(SET CMP0026 OLD)

get_target_property(sub_lib_a_file sub_lib_a LOCATION)

file(APPEND ${CMAKE_CURRENT_LIST_DIR}/nemtom.txt $<TARGET_FILE:sub_lib_a>)



list(APPEND commands COMMAND echo copy libs start)

file(REMOVE_RECURSE ${CMAKE_CURRENT_LIST_DIR}/libs)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/libs)

list(APPEND commands COMMAND cp $<TARGET_FILE:sub_lib_a> ${CMAKE_CURRENT_LIST_DIR}/libs/)
list(APPEND commands COMMAND cp $<TARGET_FILE:sub_lib_b> ${CMAKE_CURRENT_LIST_DIR}/libs/)

list(APPEND commands COMMAND echo copy libs end)

##message(FATAL_ERROR ${commands})

add_custom_command(TARGET ${PROJECT_NAME}_lib_comp PRE_BUILD ${commands})
	
	
	

get_target_property(sub_lib_b_file sub_lib_b LOCATION)

set_target_properties(${PROJECT_NAME}_lib_comp PROPERTIES STATIC_LIBRARY_FLAGS_DEBUG "${CMAKE_CURRENT_LIST_DIR}/libs/*.lib")
											 

