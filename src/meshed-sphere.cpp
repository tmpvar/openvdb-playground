#include <openvdb/openvdb.h>
#include <openvdb/tools/LevelSetSphere.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main () {
  openvdb::initialize();
  openvdb::FloatGrid::Ptr grid = openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
    /*radius=*/50.0,
    /*center=*/openvdb::Vec3f(1.5, 2, 3),
    /*voxel size=*/1,
    /*width=*/4.0
  );

  if (!glfwInit()) {
   std::cout << "glfw did not initialize!\n";
   return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSwapInterval(0);

  GLFWwindow* window = glfwCreateWindow(1024, 768, "meshed-sphere", NULL, NULL);

  if (!window) {
    std::cout << "could not crete window :(\n";
    glfwTerminate();
    return -1;
  }

  // glfwSetKeyCallback(window, key_callback);
  glfwMakeContextCurrent(window);

  // Print all active ("on") voxels by means of an iterator.
  for (openvdb::FloatGrid::ValueOnCIter iter = grid->cbeginValueOn(); iter; ++iter) {
      std::cout << "Grid" << iter.getCoord() << " = " << *iter << std::endl;
  }

  glfwTerminate();
  return 0;
}
