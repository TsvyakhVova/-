#include <cmath>
#include <iostream>

using namespace std;

int mpi() {
  setlocale(LC_ALL, "RUS");
  const int a = 3;
  const int b = 4;
  double mass[a][b] = {{5, -1, 2, 3}, {-2, -10, 3, -4}, {1, 2, 5, 12}};
  double massC[a][b];
  double massB[a];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << " " << mass[i][j];
    }
    cout << endl;
  }
  double per = 0;
  for (int i = 0; i < a; i++) {
    per = mass[i][i];
    for (int j = 0; j < b; j++) {
      mass[i][j] /= per;
      cout << mass[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Матрица С" << endl;
  if ((mass[0][0] && mass[1][1] && mass[2][2]) == 1) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        massC[i][j] = mass[i][j];
      }
      massC[i][i] = 0;
    }
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b - 1; j++) {
        cout << massC[i][j] << " ";
      }
      cout << endl;
    }
  }
  cout << "Матрица В" << endl;
  for (int i = 0; i < a; i++) {
    massB[i] = mass[i][3];
    cout << massB[i];
    cout << endl;
  }
  cout << "Шаги" << endl;
  // В-(С*на вектор)
  double rez[a] = {0, 0, 0};
  double rez1[a] = {0, 0, 0};
  double massV[a] = {0, 0, 0};
  for (int i = 0; i < a; i++) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b - 1; j++) {
        rez[i] += massC[i][j] * massV[j];
      }
    }
    for (int i = 0; i < a; i++) {
      rez1[i] = massB[i] - rez[i];
    }
    cout << i + 1 << " шаг итог" << endl;
    for (int i = 0; i < a; i++) {
      cout << rez1[i] << " ";
      cout << endl;
    }
    for (int i = 0; i < a; i++) {
      massV[i] = rez1[i];
      rez[i] = 0;
    }
  }
  cout << "Кол-во шагов N" << endl;
  double C = 0;
  double MaxC[3];
  double B = 0;
  double MaxB[3];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      MaxC[i] += abs(massC[i][j]);
    }
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (MaxC[i] >= MaxC[j])
        C = MaxC[i];
    }
  }
  for (int i = 0; i < a; i++) {
    MaxB[i] = abs(massB[i]);
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (MaxB[i] >= MaxB[j])
        B = MaxB[i];
    }
  }
  cout << "C=" << C << endl;
  cout << "B=" << B << endl;
  double N = (((log(pow(10, -4) * (1 - C) / B))) / (log(C))) + 1;
  cout << "N = " << N << endl;
  return 0;
}

int main() { mpi(); }