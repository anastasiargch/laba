#pragma once
class ProperFraction {
private:
	int _numerator;
	int _denominator;

	int NOD(int a, int b);

	void reduceFraction(); // ��������������� ����� ��� ���������� �����

public:
	ProperFraction(int numerator, int denominator); // ����������� � ����� �����������
	ProperFraction(const ProperFraction& secondFraction);// ���������� �����������

	int GetNumerator(); // ����� ��� ��������� ���������
	int GetDenominator(); // ����� ��� ��������� �����������

	// �������������� ��������
	void add(const ProperFraction& secondFraction);
	void multiply(const ProperFraction& secondFraction);
	void divide(const ProperFraction& secondFraction);

	// ���������� ����������
	ProperFraction operator+(const ProperFraction& secondFraction);
	ProperFraction operator*(const ProperFraction& secondFraction);
	ProperFraction operator/(const ProperFraction& secondFraction);

	void print() const; // ����� ������ �����
};

