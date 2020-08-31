#include <cmath>
#include <iostream>

using namespace std;

int MPD() {
  setlocale(LC_ALL, "RUS");
  double a = 1; // начальный интервал [1,2]
  double b = 2; // начальный интервал [1,2]
  // x^2-3=0 уравнение
  for (int i = 0; i < 4; i++) {
    cout << "Находим произведение значений функции в крайних точках" << endl;
    double Fa = pow(a, 2) - 3, Fb = pow(b, 2) - 3;
    double res = (Fa) * (Fb);
    cout << res << endl;
    cout << "Находим середину интервала" << endl;
    double C = (a + b) / double(2);
    cout << "C = " << C << endl;
    double Fc = pow(C, 2) - 3;
    cout << "F(c) = " << Fc << endl;
    double e = (abs(b - a) / double(2));
    cout << "e = " << e << endl;
    cout << "Новые интервалы" << endl;
    double F1 = Fa * Fc;
    double F2 = Fc * Fb;
    cout << "[" << a << "," << C << "] " << F1 << endl;
    cout << "[" << C << "," << b << "] " << F2 << endl;
    if (F1 < 0) {
      a = a;
      b = C;
    } else if (F2 < 0) {
      a = C;
      b = b;
    }
    cout << "Новый интервал"
         << "[" << a << "," << b << "]" << endl;
  }
  return 0;
}

int main() {
  MPD();
  return 0;
}