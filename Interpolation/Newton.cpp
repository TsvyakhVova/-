#include <cmath>
#include <iostream>

using namespace std;

int fact(int x) {
  int f = 1;
  for (int i = 1; i <= x; i++) {
    f *= i;
  }
  x = f;
  return x;
}

int Newton() {
  setlocale(LC_ALL, "RUS");
  double X = 1.69;
  const int a = 4;
  const int b = 3;
  double x[a] = {1, 1.5, 2, 2.5};
  double y[a] = {1.0000, 1.2247, 1.4142, 1.5811};
  double Y[a][b] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  cout << "Составим таблицу конечных разностей" << endl;
  double yy[a] = {0, 0, 0, 0};
  for (int i = 0; i < a; i++) {
    yy[i] = y[i];
  }
  int B = b;
  for (int i = 0; i < a; i++) {
    for (int j = B - 1; j >= 0; j--) {
      Y[j][i] = yy[j + 1] - yy[j];
    }
    if (i >= 0) {
      for (int k = 0; k < a; k++) {
        yy[k] = Y[k][i];
      }
    }
    B -= 1;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << Y[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Первая фомула Ньютона" << endl;
  double p = 0;
  double q = 1.38;
  double per = 1;
  double P = 0;
  for (int i = 0; i < b; i++) {
    p = (Y[0][i] / fact(i + 1));
    if (i > 0) {
      for (int j = 1; j <= i; j++) {
        per *= (q - j);
      }
    }
    q *= per;
    p *= q;
    P += p;
    cout << P << endl;
  }
  P += y[0];
  cout << P << endl;
  cout << "Вторая формула Ньютона" << endl;
  return 0;
}

int main() {
  Newton();
  return 0;
}