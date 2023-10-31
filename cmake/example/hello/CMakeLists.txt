cmake_minimum_required(VERSION 3.10)

project(main VERSION 2.5)
message(STATUS S{PROJECT_VERSION})

option(PRINT_VERSION "Whether print version or not" ON)
option(THIRD_TEST "Whether use third_party function or not" OFF)

configure_file(config.h.in config.h)

message(STATUS ${PROJECT_BINARY_DIR})
include_directories(${PROJECT_BINARY_DIR})
add_executable(main main.cpp)

if(THIRD_TEST)
	include_directories(third_party/third_test)
	add_subdirectory(third_party/third_test)
	target_link_libraries(main third_lib)
endif()