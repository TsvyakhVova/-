from sympy import diff, symbols


def derivative(pow, per):
    x = symbols('x')
    der1 = diff(x**pow-per)
    return der1
## x^2-3 

def Newton():
    f = derivative(2, 3)
    print("Производная x^2-3 = ", f)
    x = diff(f)
    X = x
    print("x0 =", x)
    for i in range(4):
        i = (x - ((x**2) - 3) / (X * x))
        x = i
        print("%.10f" % (x))


def main():
    Newton()


if __name__ == '__main__':
    main()
