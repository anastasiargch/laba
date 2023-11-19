#pragma once
class ProperFraction {
private:
	int _numerator;
	int _denominator;

	int NOD(int a, int b);

	void reduceFraction(); // вспомогательный метод для сокращения дроби

public:
	ProperFraction(int numerator, int denominator); // конструктор с двумя параметрами
	ProperFraction(const ProperFraction& secondFraction);// констуктор копирования

	int GetNumerator(); // метод для получения числителя
	int GetDenominator(); // метод для получения знаменателя

	// арифмитические операции
	void add(const ProperFraction& secondFraction);
	void multiply(const ProperFraction& secondFraction);
	void divide(const ProperFraction& secondFraction);

	// перегрузка операторов
	ProperFraction operator+(const ProperFraction& secondFraction);
	ProperFraction operator*(const ProperFraction& secondFraction);
	ProperFraction operator/(const ProperFraction& secondFraction);

	void print() const; // метод вывода дроби
};

