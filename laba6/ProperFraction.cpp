#include <iostream>
#include <cstdlib>
#include "ProperFraction.h"
using namespace std;

int ProperFraction::NOD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

void ProperFraction::reduceFraction() {
    int nod = NOD(_numerator, _denominator);
    _numerator /= nod;
    _denominator /= nod;
}

ProperFraction::ProperFraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {
    if (_denominator == 0) {
        cerr << "Denominator can't be zero!" << endl;
        system("pause");
    }
    reduceFraction();
}

ProperFraction::ProperFraction(const ProperFraction& secondFraction) {
    _numerator = secondFraction._numerator;
    _denominator = secondFraction._denominator;
}

int ProperFraction::GetNumerator() {
    return _numerator;
}

int ProperFraction::GetDenominator() {
    return _denominator;
}

void ProperFraction::add(const ProperFraction& secondFraction) {
    int newNumerator = _numerator * secondFraction._denominator + secondFraction._numerator * _denominator;
    int newDenominator = _denominator * secondFraction._denominator;
    reduceFraction();
}

void ProperFraction::multiply(const ProperFraction& secondFraction) {
    int newNumerator = _numerator * secondFraction._numerator;
    int newDenominator = _denominator * secondFraction._denominator;
    reduceFraction();
}

void ProperFraction::divide(const ProperFraction& secondFraction) {
    int newNumerator = _numerator * secondFraction._denominator;
    int newDenominator = _denominator * secondFraction._numerator;
    reduceFraction();
}

ProperFraction ProperFraction:: operator+(const ProperFraction& secondFraction) {
    int newNumerator = _numerator * secondFraction._denominator + secondFraction._numerator * _denominator;
    int newDenominator = _denominator * secondFraction._denominator;
    ProperFraction result(newNumerator, newDenominator);
    result.reduceFraction();
    return result;
}

ProperFraction ProperFraction:: operator*(const ProperFraction& secondFraction) {
    int newNumerator = _numerator * secondFraction._numerator;
    int newDenominator = _denominator * secondFraction._denominator;
    ProperFraction result(newNumerator, newDenominator);
    result.reduceFraction();
    return result;
}

    ProperFraction ProperFraction:: operator/(const ProperFraction & secondFraction) {
        int newNumerator = _numerator * secondFraction._denominator;
        int newDenominator = _denominator * secondFraction._numerator;
        ProperFraction result(newNumerator, newDenominator);
        result.reduceFraction();
        return result;
    }

void ProperFraction::print() const {
    if (_numerator == 0) {
        cout << "0";
    }
    else if (_denominator == 1) {
        cout << _numerator;
    }
    else {
        if ((_numerator < 0 && _denominator > 0) || (_numerator > 0 && _denominator < 0)) {
            cout << "-" << abs(_numerator) << "/" << abs(_denominator);
        }
        else {
            cout << abs(_numerator) << "/" << abs(_denominator);
        }
    }   
}