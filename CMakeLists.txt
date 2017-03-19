cmake_minimum_required(VERSION 3.0)

project(openvdb-tests)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(OpenVDB REQUIRED)
find_package(TBB REQUIRED)
find_package(Half REQUIRED)

include_directories(
  ${OPENVDB_INCLUDE_DIR}
  ${TBB_INCLUDE_DIRS}
  ${HALF_INCLUDE_DIR}
)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(hello-world src/hello-world.cpp)
target_link_libraries(
  hello-world
  ${OPENVDB_LIBRARY}
  ${TEST_TBB_LIBRARY}
  ${HALF_LIBRARY}
)
