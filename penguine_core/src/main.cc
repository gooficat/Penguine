#include "main.h"

#include "app.h"

int main(void)
{
  RGFW_window *window = RGFW_createWindow(
    "penguine application",
    0, 0,
    640, 360,
    RGFW_windowCenter | RGFW_windowNoResize | RGFW_windowOpenGL
  );
  RGFW_window_makeCurrentContext_OpenGL(window);
  gladLoadGL(RGFW_getProcAddress_OpenGL);

  glViewport(0, 0, 640, 360);
  glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

  while (RGFW_window_shouldClose(window) == RGFW_FALSE)
  {
    RGFW_pollEvents();
    glClear(GL_COLOR_BUFFER_BIT);


    RGFW_window_swapBuffers_OpenGL(window);
  }
  
  RGFW_window_close(window);
  return 0;
}
