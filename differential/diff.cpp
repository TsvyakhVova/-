#include <cmath>
#include <iostream>

using namespace std;

double f(double x, double y) {
  double Yr = 2 * x - y;
  return Yr;
}

double F(double x, double y) {
  double h = 0.2;
  double YR = (2 * (x + h)) - (y);
  return YR;
}

int diff() {
  setlocale(LC_ALL, "rus");
  double x = 1;
  double y = 3;
  double h = 0.2;
  for (int i = 0; i < 3; i++) {
    cout << "Шаг" << i + 1 << endl;
    f(x, y);
    cout << "f(x,y)= " << f(x, y) << endl;
    double Y = y + (h / 2) * f(x, y);
    cout << "<y>= " << Y << endl;
    F(x, Y);
    cout << "f(x+h-<y>)= " << F(x, Y) << endl;
    double yy = y + (h / 2) * (f(x, y) + F(x, Y));
    cout << "y= " << yy << endl;
    y = yy;
    x = x + h;
  }
  return 0;
}

int main() {
  diff();
  return 0;
}