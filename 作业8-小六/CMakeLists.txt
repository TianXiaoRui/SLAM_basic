cmake_minimum_required( VERSION 2.8 )
project( PlotTrajectory )
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()
MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

SET( CMAKE_CXX_FLAGS "-std=c++11" )

find_package(Pangolin REQUIRED)

include_directories("/usr/include/eigen3")
include_directories(${Pangolin_INCLUDE_DIRS})

#find_package( Sophus REQUIRED )
#include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable( PlotTrajectory PlotTrajectory.cpp)
target_link_libraries(PlotTrajectory        ${Pangolin_LIBRARIES} )
target_link_libraries(PlotTrajectory        /usr/local/lib/libSophus.so )

