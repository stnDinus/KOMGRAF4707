#include "draw_points.hxx"

#include "Matriks.hxx"
#include <format>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
  unordered_map<string, GLfloat> args;
  args["-p1x"] = 1;
  args["-p1y"] = 3;

  args["-p2x"] = 2;
  args["-p2y"] = 4;

  args["-t1x"] = 1;
  args["-t1y"] = 3;

  args["-t2x"] = 1;
  args["-t2y"] = 4;

  args["-t3x"] = 3;
  args["-t3y"] = 4;

  for (int i = 1; i < argc; i++) {
    args.at(argv[i]) = stof(argv[i + 1]);
    i++;
  }

  Matriks p1 = Matriks<GLfloat>(3, 1);
  p1.from_vec(vector<GLfloat>{
      args["-p1x"],
      args["-p1y"],
      1,
  });

  cout << "Matriks p1 awal" << endl;
  p1.print();
  draw_points(p1.to_vec());

  Matriks p1t = p1.translate_matriks(args["-t1x"], args["-t1y"]);
  cout << format("Hasil translasi matriks p1 | T({},{})", args["-t1x"],
                 args["-t1y"])
       << endl;
  p1t.print();
  draw_points(p1t.to_vec());

  Matriks p2 = Matriks<GLfloat>(3, 1);
  p2.from_vec(vector<float>{
      args["-p2x"],
      args["-p2y"],
      1,
  });
  cout << "Matriks p2 awal" << endl;
  p2.print();

  Matriks p2t = p2.translate_matriks(args["-t2x"] + args["-t3x"],
                                     args["-t2y"] + args["-t3y"]);
  cout << format("Hasil translasi matriks p2 | T({} + {}, {} + {})",
                 args["-t2x"], args["-t3x"], args["-t2y"], args["-t3y"])
       << endl;
  p2t.print();
  draw_points(p2t.to_vec());

  return 0;
}
