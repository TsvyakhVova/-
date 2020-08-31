#include <cmath>
#include <iostream>

using namespace std;

int fact(int x) {
  int f = 1;
  for (int i = 1; i <= x; i++) {
    f *= i;
  }
  x = f;
  // cout << x << endl;
  return x;
}

int Newton() {
  setlocale(LC_ALL, "RUS");
  double X = 1.69;
  double x[4] = {1, 1.5, 2, 2.5};
  double y[4] = {1.0000, 1.2247, 1.4142, 1.5811};
  double Y1[4] = {0, 0, 0, 0};
  double Y2[4] = {0, 0, 0, 0};
  double Y3[4] = {0, 0, 0, 0};
  cout << "Составим таблицу конечных разностей" << endl;
  for (int i = 3; i >= 1; i--) {
    Y1[i - 1] = y[i] - y[i - 1];
  }
  for (int i = 2; i >= 1; i--) {
    Y2[i - 1] = Y1[i] - Y1[i - 1];
  }
  for (int i = 1; i >= 1; i--) {
    Y3[i - 1] = Y2[i] - Y2[i - 1];
  }
  for (int i = 0; i < 4; i++) {
    cout << x[i] << "\t" << y[i] << "\t" << Y1[i] << "\t" << Y2[i] << "\t"
         << Y3[i] << endl;
  }
  double h = 0.5;
  double q = (X - x[0]) / h;
  // cout << q << endl;
  cout << "Первая формула Ньютона" << endl;
  double P = y[0] + ((Y1[0] / fact(1)) * q) +
             ((Y2[0] / fact(2)) * (q * (q - 1))) +
             (Y3[0] / fact(3)) * (q * (q - 1) * (q - 2));
  cout << P << endl;
  cout << "Вторая формула Ньютона" << endl;
  int n = 3;
  double Q = (X - x[3]) / h;
  double P2 = y[n] + ((Y1[n - 1] / fact(1)) * Q) +
              ((Y2[n - 2] / fact(2)) * (Q * (Q + 1))) +
              (Y3[n - 3] / fact(3)) * (Q * (Q + 1) * (Q + 2));
  cout << P2 << endl;
  return 0;
}

int main() {
  Newton();
  return 0;
}