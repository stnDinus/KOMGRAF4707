#include "draw_points.hxx"

using namespace std;

void draw_points(vector<GLfloat> points) {
  if (!glfwInit()) {
    cerr << "GLFW gagal inisialisasi" << endl;
    exit(-1);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  GLFWwindow *window = glfwCreateWindow(768, 768, "HW3", NULL, NULL);
  if (window == NULL) {
    cerr << "GLFW gagal membuat window" << endl;
    glfwTerminate();
    exit(-1);
  }
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK) {
    cerr << "GLEW gagal inisialisasi" << endl;
    exit(-1);
  }

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  GLuint vertexbuffer;
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(points[0]),
               points.data(), GL_STATIC_DRAW);

  const char *shaders_dir = getenv("SHADERS_DIR");
  if (shaders_dir == NULL) {
    cerr << "Pastikan environment variable SHADERS_DIR bernilai" << endl;
    exit(-1);
  }
  GLuint programID =
      loadShaders((string(shaders_dir) + "/VertexShader.glsl").c_str(),
                  (string(shaders_dir) + "/FragmentShader.glsl").c_str());

  glPointSize(10);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glDrawArrays(GL_POINTS, 0, points.size() / 3);

    glDisableVertexAttribArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();

  } while (glfwWindowShouldClose(window) == 0);
}
