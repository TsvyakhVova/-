#include <cmath>
#include <iostream>

using namespace std;

int gauss() {
  setlocale(LC_ALL, "RUS");
  const int a = 3;
  const int b = 4;
  double mass[a][b] = {{-2, 1, -3, -8}, {3, 1, -6, -9}, {1, 1, 2, 5}};
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (j == b - 1) {
        cout << "|";
      }
      cout << mass[i][j] << "\t";
    }
    cout << endl;
  }
  double M[1][b];
  int J = 0;
  cout << endl;
  double del[a];
  for (int i = 0; i < b - 2; i++) {
    if (abs(mass[i + 1][J]) > abs(mass[0][J])) {
      for (int i = 0; i < 1; i++) {
        for (int j = 0; j < b; j++) {
          M[i][j] = mass[i][j];
          mass[i][j] = mass[i + 1][j];
          mass[i + 1][j] = M[i][j];
        }
      }
    }
    J += 1;
    cout << endl;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (j == 3) {
          cout << "|";
        }
        cout << mass[i][j] << "\t";
      }
      cout << endl;
    }
    for (int j = i + 1; j < a; j++) {
      del[j - 1] = mass[j][i] / mass[i][i];
      if (del[j - 1] < 0) {
        del[j - 1] = abs(del[j - 1]);
      } else if (del[j - 1] > 0) {
        del[j - 1] = -del[j - 1];
      }
    }
    for (int I = i + 1; I < a; I++) {
      for (int J = i; J < b; J++) {
        mass[I][J] += mass[i][J] * del[I - 1];
      }
    }
  }
  cout << "Матрица приведённая к треугольному виду" << endl;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (j == 3) {
        cout << "|";
      }
      cout << mass[i][j] << "\t";
    }
    cout << endl;
  }
  double x[a];
  x[a - 1] = mass[a - 1][b - 1] / mass[a - 1][b - 2];
  for (int i = a - 2; i >= 0; i--) {
    for (int j = b - 2; j > i; j--) {
      x[i] = mass[i][b - 1] - (mass[i][j] * x[j]);
      mass[i][b - 1] = x[i];
    }
    x[i] /= mass[i][i];
  }
  for (int i = a - 1; i >= 0; i--) {
    cout << "x[" << i + 1 << "]= " << x[i] << endl;
  }
  return 0;
}

int main() {
  gauss();
  return 0;
}