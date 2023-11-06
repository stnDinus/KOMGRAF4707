#include "draw_points.hxx"

using namespace std;

void draw_points(vector<GLfloat> points, string title) {
  // set steps = absolute max value int + 1
  int steps = 0;
  for (GLfloat i : points) {
    int absInt = abs(i);
    if (absInt > steps)
      steps = absInt;
  }
  steps++;

  // scale each coordinates relative to steps
  for (int i = 0; i < points.size(); i++)
    points[i] /= steps + 1;

  // set coordinate lines
  vector<GLfloat> lines(steps * 24 + 12);
  // step lines
  for (GLfloat i = 0; i < steps; i++) {
    int ilines = 24, i2 = 0;
    // +x line start
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1); // x
    lines[i * ilines + i2++] = 0.01;                   // y
    lines[i * ilines + i2++] = 0;                      // z
    // +x lines end
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1); // x
    lines[i * ilines + i2++] = -0.01;                  // y
    lines[i * ilines + i2++] = 0;                      // z
    // -x line start
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1) * -1; // x
    lines[i * ilines + i2++] = 0.01;                        // y
    lines[i * ilines + i2++] = 0;                           // z
    // -x lines end
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1) * -1; // x
    lines[i * ilines + i2++] = -0.01;                       // y
    lines[i * ilines + i2++] = 0;                           // z
    // +y line start
    lines[i * ilines + i2++] = 0.01;                   // x
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1); // y
    lines[i * ilines + i2++] = 0;                      // z
    // +y lines end
    lines[i * ilines + i2++] = -0.01;                  // x
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1); // y
    lines[i * ilines + i2++] = 0;                      // z
    // -y line start
    lines[i * ilines + i2++] = 0.01;                        // x
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1) * -1; // y
    lines[i * ilines + i2++] = 0;                           // z
    // -y line end
    lines[i * ilines + i2++] = -0.01;                       // x
    lines[i * ilines + i2++] = (i + 1.) / (steps + 1) * -1; // y
    lines[i * ilines + i2++] = 0;                           // z
  }
  // cord lines
  lines[lines.size() - 1 - 11] = -1;
  lines[lines.size() - 1 - 10] = 0;
  lines[lines.size() - 1 - 9] = 0;
  lines[lines.size() - 1 - 8] = 1;
  lines[lines.size() - 1 - 7] = 0;
  lines[lines.size() - 1 - 6] = 0;
  lines[lines.size() - 1 - 5] = 0;
  lines[lines.size() - 1 - 4] = -1;
  lines[lines.size() - 1 - 3] = 0;
  lines[lines.size() - 1 - 2] = 0;
  lines[lines.size() - 1 - 1] = 1;
  lines[lines.size() - 1 - 6] = 0;

  if (!glfwInit()) {
    cerr << "GLFW gagal inisialisasi" << endl;
    exit(-1);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  GLFWwindow *window = glfwCreateWindow(768, 768, title.c_str(), NULL, NULL);
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

  GLuint VertextBuffer1ID;
  glGenBuffers(1, &VertextBuffer1ID);
  glBindBuffer(GL_ARRAY_BUFFER, VertextBuffer1ID);
  glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(points[0]),
               points.data(), GL_STATIC_DRAW);

  GLuint VertextBuffer2ID;
  glGenBuffers(1, &VertextBuffer2ID);
  glBindBuffer(GL_ARRAY_BUFFER, VertextBuffer2ID);
  glBufferData(GL_ARRAY_BUFFER, lines.size() * sizeof(lines[0]), lines.data(),
               GL_STATIC_DRAW);

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
    glBindBuffer(GL_ARRAY_BUFFER, VertextBuffer1ID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glDrawArrays(GL_POINTS, 0, points.size() / 3);

    glBindBuffer(GL_ARRAY_BUFFER, VertextBuffer2ID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glDrawArrays(GL_LINES, 0, lines.size() / 3);

    glDisableVertexAttribArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();

  } while (glfwWindowShouldClose(window) == 0);
}
