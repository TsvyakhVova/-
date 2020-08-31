#include <cmath>
#include <iostream>

using namespace std;

int Aitken() {
  double X = 2.56;
  int x[4] = {1, 2, 3, 4};
  double y[4] = {1.0000, 1.4142, 1.7321, 2.0000};
  double Px[4];
  double Pxx[3][4];
  double P3[2];
  double P4[1];
  for (int i = 0; i < 4; i++) {
    Px[i] = y[i];
  }
  for (int i = 0; i < 3; i++) {
    Pxx[i][i + 1] = ((Px[i] * (X - x[i + 1])) - (Px[i + 1] * (X - x[i]))) /
                    (x[i] - x[i + 1]);
  }
  for (int i = 0; i < 2; i++) {
    P3[i] =
        ((Pxx[i][i + 1] * (X - x[i + 2])) - (Pxx[i + 1][i + 2] * (X - x[i]))) /
        (x[i] - x[i + 2]);
  }
  for (int i = 0; i < 1; i++) {
    P4[i] = ((P3[i] * (X - x[i + 3])) - (P3[i + 1] * (X - x[i]))) /
            (x[i] - x[i + 3]);
  }
  cout << Pxx[0][1] << " " << P3[0] << " " << P4[0] << endl;
  cout << Pxx[1][2] << " " << P3[1] << endl;
  cout << Pxx[2][3] << endl;
  return 0;
}

int main() {
  Aitken();
  return 0;
}