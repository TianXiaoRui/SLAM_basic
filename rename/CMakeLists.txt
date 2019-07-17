cmake_minimum_required(VERSION 2.8)

project(rename)

FIND_PACKAGE(OpenCV 3.2.0 REQUIRED)

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "rename.cpp")

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})