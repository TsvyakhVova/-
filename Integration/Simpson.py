from sympy import integrate, symbols
import numpy as massive


def Integration(a, b):
    x = symbols('x')
    h = integrate(1/x, (x, a, b))
    return h


def Simpson():
    x = massive.array([1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2])
    y = massive.array([1, 0.9091, 0.8333, 0.7692, 0.7142,
                       0.6667, 0.625, 0.5882, 0.5556, 0.5263, 0.5])
    size = len(x)
    integrale = Integration(x[0], x[10])
    P = 0
    t = 0
    I = 0
    for i in range(size):
        if t > size-2:
            break
        rez = Integration(x[i], x[i+1])
        f = (x[t+2] - x[t])*(1/6*y[I] + 2/3*y[I+1] + 1/6*y[I+2])
        print('\n')
        print(x[t+2])
        print("|", "%.5f" % (rez), "=", "%.4f" % (f))
        print(x[t])
        P = P + f
        t += 2
        I += 2
    print("\n", "%.5f" % (integrale), "=", "%.5f" % (P))


def main():
    Simpson()


if __name__ == '__main__':
    main()
