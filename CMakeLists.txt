cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME pneumatic-testbed)
set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION 1)
project(${PROJECT_NAME})

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")

set(SOURCES
	"${SRC_DIR}/Main.cpp")

# Pneumatic
#===========
set(PNEUMATIC_DIR "${LIB_DIR}/pneumatic")
set(PNEUMATIC_INCLUDE_DIRS "${PNEUMATIC_DIR}/include")
set(PNEUMATIC_LIBRARIES "pneumatic")

add_subdirectory(${PNEUMATIC_DIR})
link_directories(${PNEUMATIC_DIR})
include_directories(${PNEUMATIC_INCLUDE_DIRS})

set(GLM_INCLUDE_DIRS "${PNEUMATIC_DIR}/thirdparty/glm")
include_directories(${GLM_INCLUDE_DIRS})

# Building
#==========

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

add_definitions(
	-std=c++1y
	-Wall)

target_link_libraries("${PROJECT_NAME}"
	"${PNEUMATIC_LIBRARIES}")
