#include <cmath>
#include <iostream>

using namespace std;

int Aitken() {
  double X = 2.56;
  const int a = 4;
  int x[a] = {1, 2, 3, 4};
  double y[a] = {1.0000, 1.4142, 1.7321, 2.0000};
  double P[a];
  for (int i = 0; i < a; i++) {
    P[i] = y[i];
  }
  for (int i = 0; i < a - 1; i++) {
    int J = 0;
    for (int j = i; j < a - 1; j++) {
      P[J] = ((P[J] * (X - x[j + 1])) - (P[J + 1] * (X - x[J]))) /
             (x[J] - x[j + 1]);
      cout << "P[" << J << "]= " << P[J] << endl;
      J += 1;
    }
    J = 0;
  }
  return 0;
}

int main() {
  Aitken();
  return 0;
}