#include <cmath>
#include <iostream>

using namespace std;

int fact(int x) {
  int f = 1;
  for (int i = 1; i <= x; i++) {
    f *= i;
  }
  x = f;
  // cout << f << endl;
  return x;
}

int Langrage() {
  setlocale(LC_ALL, "RUS");
  const int a = 4;
  double X = 2.56;
  int x[a] = {1, 2, 3, 4};
  double y[a] = {1.000, 1.4124, 1.7321, 2.000};
  for (int i = 0; i < a; i++) {
    cout << x[i] << "||" << y[i] << endl;
  }
  cout << "Т.к имеем 4 узла интерполяции, то найти Р3(х) по формуле" << endl;
  double F1 = y[0] * (((X - x[1]) * (X - x[2]) * (X - x[3])) /
                      ((x[0] - x[1]) * (x[0] - x[2]) * (x[0] - x[3])));
  double F2 = y[1] * (((X - x[0]) * (X - x[2]) * (X - x[3])) /
                      ((x[1] - x[0]) * (x[1] - x[2]) * (x[1] - x[3])));
  double F3 = y[2] * (((X - x[0]) * (X - x[1]) * (X - x[3])) /
                      ((x[2] - x[0]) * (x[2] - x[1]) * (x[2] - x[3])));
  double F4 = y[3] * (((X - x[0]) * (X - x[1]) * (X - x[2])) /
                      ((x[3] - x[0]) * (x[3] - x[1]) * (x[3] - x[2])));
  cout << F1 << " " << F2 << " " << F3 << " " << F4 << endl;
  double P3 = F1 + F2 + F3 + F4;
  cout << P3 << endl;
  cout << "Найдем погрешности учечения, округления и реальную" << endl;
  double M = 15.0 / 16.0;
  double Ey = (M / fact(4)) * ((X - 1) * (X - 2) * (X - 3) * (X - 4));
  double Eo = 5 * pow(10, -5);
  double Er = Ey + Eo;
  cout << Er << endl;
  return 0;
}

int main() {
  Langrage();
  return 0;
}