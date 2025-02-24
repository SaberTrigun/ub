cmake_minimum_required(VERSION 3.10)

project(myProj)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(SOURCES_DIR "class")
set(LIB_DIR "lib")

set(CMAKE_OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj)

set(SOURCES
	main.cpp
	stb_image/stb_image.cpp
	${SOURCES_DIR}/buttons.cpp
	${SOURCES_DIR}/camera.cpp
	${SOURCES_DIR}/inputHandler.cpp
	${SOURCES_DIR}/shader.cpp
	${SOURCES_DIR}/simpleBox.cpp
	${SOURCES_DIR}/texture.cpp
)

find_library(LIB_GLFW3 NAMES glfw3 PATHS ${LIB_DIR})
if(NOT LIB_GLFW3)
    message(FATAL_ERROR "I am not found glfw3 â ${LIB_DIR}")
endif()



add_executable(bin.exe ${SOURCES})


target_link_libraries(bin.exe PRIVATE ${LIB_GLFW3})