#include <cmath>
#include <iostream>

using namespace std;

int mpi() {
  setlocale(LC_ALL, "RUS");
  const int a = 3;
  const int b = 4;
  double mass[a][b] = {{5, -1, 2, 3}, {-2, -10, 3, -4}, {1, 2, 5, 12}};
  double massC[a][b];
  double massB[a][1];
  for (int i = 0; i < a; i++) {   // строка
    for (int j = 0; j < b; j++) { // столбец
      cout << " " << mass[i][j];
    }
    cout << endl;
  }
  double per = 0;
  for (int i = 0; i < a; i++) { //// получаем единицы на главной диагонали
    per = mass[i][i];
    for (int j = 0; j < b; j++) {
      mass[i][j] /= per;
      cout << mass[i][j] << " ";
    }
    cout << endl;
  } ///////////////////////////////////////
  cout << "Матрица С" << endl;
  if ((mass[0][0] && mass[1][1] && mass[2][2]) == 1) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        massC[i][j] = mass[i][j];
      }
    }
    massC[0][0] = 0;
    massC[1][1] = 0;
    massC[2][2] = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b - 1; j++) {
        cout << massC[i][j] << " ";
      }
      cout << endl;
    }
  }
  cout << "Матрица В" << endl;
  for (int i = 0; i < a; i++) {
    for (int b = 0; b < 1; b++) {
      massB[i][0] = mass[i][3];
      cout << massB[i][0];
    }
    cout << endl;
  }
  cout << "Шаги" << endl;
  // В-(С*на вектор)
  double massV[a][1] = {0, 0, 0};
  for (int i = 0; i < 3; i++) {
    double rez[a][1];
    double rez1[a][1];
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b - 1; j++) {
        rez[i][0] += massC[i][j] * massV[j][0]; // умножение матрицы С на вектор
      }
    }
    for (int i = 0; i < a; i++) {
      rez1[i][0] =
          massB[i][0] - rez[i][0]; /// Вычитание матрицы В из результата
                                   /// умножения матриц С на вектор
    }
    cout << i + 1 << " шаг итог" << endl;
    for (int i = 0; i < a; i++) {
      cout << rez1[i][0] << " ";
      cout << endl;
    }
    for (int i = 0; i < a; i++) { //// новые данные для вектора
      massV[i][0] = rez1[i][0];
    }
  }
  cout << "Кол-во шагов N" << endl;
  double C = 0;
  double MaxC[3];
  MaxC[0] = abs(massC[0][1]) + abs(massC[0][2]);
  MaxC[1] = abs(massC[1][0]) + abs(massC[1][2]);
  MaxC[2] = abs(massC[2][0]) + abs(massC[2][1]);
  cout << MaxC[0] << " " << MaxC[1] << " " << MaxC[2] << endl;
  if ((MaxC[0] >= MaxC[1]) && (MaxC[0] >= MaxC[2])) {
    C = MaxC[0];
  } else if ((MaxC[1] >= MaxC[0]) && (MaxC[1] >= MaxC[2])) {
    C = MaxC[1];
  } else if ((MaxC[2] >= MaxC[1]) && (MaxC[2] >= MaxC[0])) {
    C = MaxC[2];
  }
  cout << C << endl;
  double B = 0;
  if ((massB[0][1] > massB[1][1]) && (massB[0][1] > massB[2][1])) {
    B = massB[0][1];
  } else if (massB[1][1] > (massB[0][1] && massB[2][1])) {
    B = massB[1][1];
  } else if (massB[2][1] > (massB[0][1] && massB[1][1])) {
    B = massB[2][1];
  }
  cout << B << endl;
  double N = (((log(pow(10, -4) * (1 - C) / B))) / (log(C))) + 1;
  cout << "N = " << N << endl;
  return 0;
}

int main() { mpi(); }