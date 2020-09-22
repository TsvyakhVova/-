#include <cmath>
#include <iostream>

using namespace std;

int Langrage() {
  setlocale(LC_ALL, "RUS");
  const int a = 4;
  double X = 2.56;
  int x[a] = {1, 2, 3, 4};
  double y[a] = {1.000, 1.4124, 1.7321, 2.000};
  for (int i = 0; i < a; i++) {
    cout << x[i] << "||" << y[i] << endl;
  }
  double P3[4];
  double per = 1;
  cout << "Т.к имеем 4 узла интерполяции, то найти Р3(х) по формуле" << endl;
  double F[a];
  double P = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (i != j) {
        per *= (X - x[j]) / (x[i] - x[j]);
      }
    }
    per *= y[i];
    F[i] = per;
    per = 1;
    P += F[i];
  }
  cout << P << endl;
  return 0;
}

int main() {
  Langrage();
  return 0;
}