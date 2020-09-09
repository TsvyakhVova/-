#include <cmath>
#include <iostream>

using namespace std;

int Zeidel() {
  setlocale(LC_ALL, "RUS");
  const int a = 3;
  const int b = 4;
  double mass[a][b] = {{5, -1, 2, 3}, {-2, -10, 3, -4}, {1, 2, 5, 12}};
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
  const int k = 3;
  double x1 = 0;
  double x2 = 0;
  double x3 = 0;
  double res[k];
  for (int i = 0; i < 3; i++) {
    cout << "Шаг" << i + 1 << endl;
    for (int i = 0; i < a; i++) {
      if (mass[i][i] == 1) {
        mass[i][i] = 0;
      }
      res[i] = mass[i][3] - ((mass[i][0] * x1) + (mass[i][1] * x2) +
                             (mass[i][2] * x3)); // x1
      // 1 = 0,6 − (−0,2 ∙ 0 + 0,4 ∙ 0) = 0,6
      if (i == 0) { // условие для новых координатов в методе Зейделя x1 x2 x3
        x1 = res[i];
      } else if (i == 1) {
        x2 = res[i];
      } else if (i == 2) {
        x3 = res[i];
      } else {
        cout << "-" << endl;
      }
    }
    for (int i = 0; i < k; i++) {
      cout << res[i] << " " << endl;
    }
  }
  cout << "Шаги" << endl;
  cout << "Кол-во шагов N" << endl;
  double C = 0;
  double MaxC[3];
  MaxC[0] = abs(mass[0][1]) + abs(mass[0][2]);
  MaxC[1] = abs(mass[1][0]) + abs(mass[1][2]);
  MaxC[2] = abs(mass[2][0]) + abs(mass[2][1]);
  if ((MaxC[0] >= MaxC[1]) && (MaxC[0] >= MaxC[2])) {
    C = MaxC[0];
  } else if ((MaxC[1] >= MaxC[0]) && (MaxC[1] >= MaxC[2])) {
    C = MaxC[1];
  } else if ((MaxC[2] >= MaxC[1]) && (MaxC[2] >= MaxC[0])) {
    C = MaxC[2];
  }
  double B = 0;
  double MaxB[3];
  for (int i = 0; i < a; i++) {
    MaxB[i] = abs(mass[i][3]);
  }
  if ((MaxB[0] >= MaxB[1]) && (MaxB[0] >= MaxB[2])) {
    B = MaxB[0];
  } else if ((MaxB[1] >= MaxB[0]) && (MaxB[1] >= MaxB[2])) {
    B = MaxB[1];
  } else if ((MaxB[2] >= MaxB[0]) && (MaxB[2] >= MaxB[1])) {
    B = MaxB[2];
  }
  double N = (((log(pow(10, -4) * (1 - C) / B))) / (log(C))) + 1;
  cout << "N = " << N << endl;
  return 0;
}

int main() { Zeidel(); }