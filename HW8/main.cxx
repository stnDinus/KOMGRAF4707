#include "draw_points.hxx"

#include "Matriks.hxx"
#include <format>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Constraint {
  GLfloat xmin, ymin, xmax, ymax;

  void print();
};

struct TBRL {
  bool t, b, r, l;

  TBRL(Constraint *c, GLfloat x, GLfloat y);

  static void printTableHeader();
  void printTableRow();
};

// Hitung gradien garis
GLfloat calcM(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
// Hitung titik potong
void calcTpTo(TBRL *tbrl, Constraint *c, GLfloat m, GLfloat x, GLfloat y,
              GLfloat *tp);

int main(int argc, char *argv[]) {
  unordered_map<string, string> env;
  env["-p1x"] = "-1";
  env["-p1y"] = "-2";
  env["-p2x"] = "5";
  env["-p2y"] = "6";
  env["-q1x"] = "-1";
  env["-q1y"] = "5";
  env["-q2x"] = "6";
  env["-q2y"] = "7";
  env["-xmin"] = "1";
  env["-ymin"] = "1";
  env["-xmax"] = "4";
  env["-ymax"] = "5";
  for (int i = 1; i < argc; i++) {
    env[argv[i]] = argv[i + 1];
    i++;
  }

  cout << "Matriks P" << endl;
  Matriks p = Matriks<GLfloat>(3, 2);
  p.from_vec(vector<GLfloat>{
      stof(env["-p1x"]),
      stof(env["-p1y"]),
      1,
      stof(env["-p2x"]),
      stof(env["-p2y"]),
      1,
  });
  p.print();
  draw_points(p.to_vec());
  cout << endl;

  cout << "Matriks Q" << endl;
  Matriks q = Matriks<GLfloat>(3, 2);
  q.from_vec(vector<GLfloat>{
      stof(env["-q1x"]),
      stof(env["-q1y"]),
      1,
      stof(env["-q2x"]),
      stof(env["-q2y"]),
      1,
  });
  draw_points(q.to_vec());
  q.print();
  cout << endl;

  cout << "Batasan(Constraint)" << endl;
  Constraint c;
  c.xmin = stof(env["-xmin"]);
  c.ymin = stof(env["-ymin"]);
  c.xmax = stof(env["-xmax"]);
  c.ymax = stof(env["-ymax"]);
  c.print();
  draw_points(vector<GLfloat>{
      c.xmin, c.ymin, 1, //
      c.xmax, c.ymin, 1, //
      c.xmin, c.ymax, 1, //
      c.xmax, c.ymax, 1, //
  });
  cout << endl;

  cout << "Tabel TBRL" << endl;
  TBRL p1Tbrl = TBRL(&c, p.arr_2d[0][0], p.arr_2d[1][0]);
  TBRL p2Tbrl = TBRL(&c, p.arr_2d[0][1], p.arr_2d[1][1]);
  TBRL q1Tbrl = TBRL(&c, q.arr_2d[0][0], q.arr_2d[1][0]);
  TBRL q2Tbrl = TBRL(&c, q.arr_2d[0][1], q.arr_2d[1][1]);
  TBRL::printTableHeader();
  cout << "p1\t";
  p1Tbrl.printTableRow();
  cout << "p2\t";
  p2Tbrl.printTableRow();
  cout << "q1\t";
  q1Tbrl.printTableRow();
  cout << "q2\t";
  q2Tbrl.printTableRow();
  cout << endl;

  cout << "Gradien" << endl;
  GLfloat pM = calcM( //
      p.arr_2d[0][0], //
      p.arr_2d[1][0], //
      p.arr_2d[0][1], //
      p.arr_2d[1][1]  //
  );
  GLfloat qM = calcM( //
      q.arr_2d[0][0], //
      q.arr_2d[1][0], //
      q.arr_2d[0][1], //
      q.arr_2d[1][1]  //
  );
  cout                                 //
      << format("Gradien P: {}\n", pM) //
      << format("Gradien Q: {}\n", qM) //
      << endl;

  cout << "Titik Potong" << endl;
  GLfloat tpP1[2];
  calcTpTo(&p1Tbrl, &c, pM, p.arr_2d[0][0], p.arr_2d[1][0], tpP1);
  GLfloat tpP2[2];
  calcTpTo(&p2Tbrl, &c, pM, p.arr_2d[0][1], p.arr_2d[1][1], tpP2);
  GLfloat tpQ1[2];
  calcTpTo(&q1Tbrl, &c, qM, q.arr_2d[0][0], q.arr_2d[1][0], tpQ1);
  GLfloat tpQ2[2];
  calcTpTo(&q2Tbrl, &c, qM, q.arr_2d[0][1], q.arr_2d[1][1], tpQ2);
  cout                                            //
      << format("P1({}, {})\n", tpP1[0], tpP1[1]) //
      << format("P2({}, {})\n", tpP2[0], tpP2[1]) //
      << format("Q1({}, {})\n", tpQ1[0], tpQ1[1]) //
      << format("Q1({}, {})\n", tpQ2[0], tpQ2[1]) //
      << endl;

  return 0;
}

void Constraint::print() {
  cout                            //
      << "xmin: " << xmin << "\n" //
      << "ymin: " << ymin << "\n" //
      << "xmax: " << xmax << "\n" //
      << "ymax: " << ymax << endl;
}

TBRL::TBRL(Constraint *c, GLfloat x, GLfloat y) {
  t = y > c->ymax;
  b = y < c->ymin;
  r = x > c->xmax;
  l = x < c->xmin;
}

void TBRL::printTableHeader() { cout << "\t(T)op\t(B)tm\t(R)ight\t(L)eft\n"; }

void TBRL::printTableRow() {
  cout                                                //
      << format("{:d}\t{:d}\t{:d}\t{:d}", t, b, r, l) //
      << endl;
}

GLfloat calcM(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
  return abs(y2 - y1) / abs(x2 - x1);
}

void calcTpTo(TBRL *tbrl, Constraint *c, GLfloat m, GLfloat x, GLfloat y,
              GLfloat *tp) {
  if (tbrl->t) {
    GLfloat xp2 = x + ((c->ymax - y) / m);
    if (c->xmin < xp2 && xp2 < c->xmax) {
      tp[0] = xp2;
      tp[1] = c->ymax;
      return;
    }
  }

  if (tbrl->b) {
    GLfloat xp1 = x + ((c->ymin - y) / m);
    if (c->xmin < xp1 && xp1 < c->xmax) {
      tp[0] = xp1;
      tp[1] = c->ymin;
      return;
    }
  }

  if (tbrl->r) {
    GLfloat yp2 = y + m * (c->xmax - x);
    if (c->ymin < yp2 && yp2 < c->ymax) {
      tp[0] = c->xmax;
      tp[1] = yp2;
      return;
    };
  }

  if (tbrl->l) {
    GLfloat yp1 = y + m * (c->xmin - x);
    if (c->ymin < yp1 && yp1 < c->ymax) {
      tp[0] = c->xmin;
      tp[1] = yp1;
      return;
    };
  }

  tp[0] = x;
  tp[1] = y;
}
