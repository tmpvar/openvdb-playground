cmake_minimum_required(VERSION 3.0)

project(openvdb-tests)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(OpenVDB REQUIRED)
find_package(TBB REQUIRED)
find_package(Half REQUIRED)
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw-3.2.1)

include_directories(
  ${OPENVDB_INCLUDE_DIR}
  ${TBB_INCLUDE_DIRS}
  ${HALF_INCLUDE_DIR}
  ${GLFW_INCLUDE_DIR}
)

SET(CMAKE_CXX_FLAGS "-std=c++0x -g -march=native")
SET(CMAKE_LINKER_FLAGS "-Wl,-rpath,/usr/local/opt/tbb/lib/lib -L/usr/local/opt/tbb/lib/lib")

# hello world
add_executable(hello-world src/hello-world.cpp)
target_link_libraries(
  hello-world
  ${OPENVDB_LIBRARY}
  ${TBB_tbb_LIBRARY_RELEASE}
  ${HALF_LIBRARY}
  ${OPENGL_INCLUDE_DIR}
)

# meshed sphere
add_executable(meshed-sphere src/meshed-sphere.cpp)
target_link_libraries(
  meshed-sphere
  ${OPENVDB_LIBRARY}
  ${TBB_tbb_LIBRARY_RELEASE}
  ${HALF_LIBRARY}
  ${OPENGL_gl_LIBRARY}
  glfw
)
