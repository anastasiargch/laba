#include "ProperFraction.h"
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Input numerator 1: ";
    cin >> a;
    cout << "Input denominator 1: ";
    cin >> b;
    ProperFraction f1(a, b);

    int c, d;
    cout << "Input numerator 2: ";
    cin >> c;
    cout << "Input denominator 2: ";
    cin >> d;
    ProperFraction f2(c, d);

    cout << "Fraction 1: ";
    f1.print();
    cout << endl;

    cout << "Fraction 2: ";
    f2.print();
    cout << endl;

    ProperFraction sum = f1 + f2;
    ProperFraction product = f1 * f2;
    ProperFraction quotient = f1 / f2;

    cout << "f1 + f2 = ";
    sum.print();
    cout << endl;

    cout << "f1 * f2 = ";
    product.print();
    cout << endl;

    cout << "f1 / f2 = ";
    quotient.print();
    cout << endl;

    return 0;
}