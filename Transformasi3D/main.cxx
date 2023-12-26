#include "Matriks.hxx"
#include "degs_to_rads.hxx"
#include "parse_args.hxx"
#include <format>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Args a;
  // NILAI DEFAULT
  a["-x"] = "1";
  a["-y"] = "4";
  a["-z"] = "4";
  a["-tx"] = "3";
  a["-ty"] = "3";
  a["-tz"] = "1";
  a["-sx"] = "4";
  a["-sy"] = "4";
  a["-sz"] = "3";
  a["-rx"] = "3";
  a["-ry"] = "1";
  a["-rz"] = "4";

  a.parse_args(&argc, argv);

  cout << "Matriks Awal" << endl;
  Matriks<GLfloat> m(4, 1);
  m.from_vec(vector<GLfloat>{
      stof(a["-x"]), //
      stof(a["-y"]), //
      stof(a["-z"]), //
      1,             //
  });
  m.print();

  cout << format(                       //
              "Translasi ({}, {}, {})", //
              a["-tx"],                 //
              a["-ty"],                 //
              a["-tz"]                  //
              )
       << endl;
  Matriks<GLfloat> mt = m.translate_matriks_3d( //
      stof(a["-tx"]),                           //
      stof(a["-ty"]),                           //
      stof(a["-tz"])                            //
  );
  mt.print();

  cout << format("Scale ({}, {}, {})", //
                 a["-sx"],             //
                 a["-sy"],             //
                 a["-sz"]              //
                 )
       << endl;
  Matriks<GLfloat> ms = mt.scale_matriks_3d( //
      stof(a["-sx"]),                        //
      stof(a["-sy"]),                        //
      stof(a["-sz"])                         //
  );
  ms.print();

  Matriks<GLfloat> mrx = ms.rotate_matriks_3d_x(degs_to_rads(stof(a["-rx"])));
  cout << format("Rotate X ({} degs)", a["-rx"]) << endl;
  mrx.print();

  Matriks<GLfloat> mry = mrx.rotate_matriks_3d_y(degs_to_rads(stof(a["-ry"])));
  cout << format("Rotate Y ({} degs)", a["-ry"]) << endl;
  mry.print();

  Matriks<GLfloat> mrz = mry.rotate_matriks_3d_z(degs_to_rads(stof(a["-rz"])));
  cout << format("Rotate Z ({} degs)", a["-rz"]) << endl;
  mrz.print();

  return 0;
}
