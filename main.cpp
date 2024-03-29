#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>

int main() {
  std::cout << "starting..........";

  GLFWwindow* window;

  // Initialize the library
  if (!glfwInit()) {
    std::cout << "failed to initialize GLFW library";
    return -1;
  }

  window = glfwCreateWindow(640, 480, "open gl test", NULL, NULL);
  if(!window) {
    glfwTerminate();
    std::cout << "Failed to create window";
    return -1;
  }

  glfwMakeContextCurrent(window);
  
  if(glewInit() != GLEW_OK) {
    glfwDestroyWindow(window);
    glfwTerminate();
    return -1;
  }

  float positions[6] = {
    0.0f, 0.5f,
    -0.5f, -0.5f,
    0.5f, -0.5f,
  };
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*)0);

  while(!glfwWindowShouldClose(window)) {
    // render here
   



    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.4f, 0.4f, 0.4f);    // Red

    glDrawArrays(GL_TRIANGLES, 0, 3);
    //
    //

    glfwSwapBuffers(window);
    glfwPollEvents();



  }

  glfwTerminate();

  return 0;
}


