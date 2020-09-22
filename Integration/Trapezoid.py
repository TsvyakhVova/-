from sympy import integrate, symbols
import numpy as massive


def Integration(a, b):
    x = symbols('x')
    h = integrate(1/x, (x, a, b))
    return h


def Trapezoid():
    x = massive.array([1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2])
    y = massive.array([1, 0.9091, 0.8333, 0.7692, 0.7142,
                       0.6667, 0.625, 0.5882, 0.5556, 0.5263, 0.5])
    size = len(x)
    integrale = Integration(x[0], x[10])
    I = 0
    for i in range(size-1):
        rez = Integration(x[i], x[i+1])
        f = (x[i+1] - x[i])*(1/2*y[i] + 1/2*y[i+1])
        print('\n')
        print(x[i+1])
        print("|", "%.5f" % (rez), "=", "%.4f" % (f))
        print(x[i])
        I = I + f
    print("\n", "%.5f" % (integrale), "=", "%.5f" % (I))


def main():
    Trapezoid()


if __name__ == '__main__':
    main()
