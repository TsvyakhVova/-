#include <cmath>
#include <iostream>

using namespace std;

int hord() {
  setlocale(LC_ALL, "rus");
  double a = 1;
  double b = 2;
  // x^2-3=0 уравнение
  // cout << "Находим произведение значений функции в крайних точках" << endl;
  for (int i = 0; i < 3; i++) {
    double Fa = pow(a, 2) - 3, Fb = pow(b, 2) - 3;
    cout << "Шаг " << i + 1 << endl;
    double c = ((a * (Fb)) - (b * (Fa))) / ((Fb) - (Fa));
    double Fc = pow(c, 2) - 3;
    cout << "С = " << c << endl;
    cout << "Интервалы " << endl;
    double I1 = Fa * Fc;
    double I2 = Fc * Fb;
    cout << "[" << a << "," << c << "] "
         << "f(a) * f(c) = " << I1 << endl;
    cout << "[" << c << "," << b << "] "
         << "f(c) * f(b) = " << I2 << endl;
    if (I1 < 0) {
      a = a;
      b = c;
    } else if (I2 < 0) {
      a = c;
      b = b;
    }
    cout << "Новый интервал [" << a << "," << b << "]" << endl;
  }
  return 0;
}

int main() {
  hord();
  return 0;
}