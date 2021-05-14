#pragma once
#include<iostream>
#include<string>

class Fraction {
private:
	int numerator, denaminator;
	friend std::ostream& operator<< (std::ostream& out, const Fraction& ovrl);
	friend std::istream& operator>> (std::istream& in, Fraction& ovrl);
public:
	Fraction();
	Fraction(int a1, int b1);
	Fraction(const Fraction& lnk);
	Fraction(Fraction&& llnk);

	Fraction operator= (Fraction ovrl);

	friend Fraction operator* (const Fraction& ovrl1, const Fraction& ovrl2);
	friend Fraction operator/ (const Fraction& ovrl1, const Fraction& ovrl2);
	friend Fraction operator- (const Fraction& ovrl1, const Fraction& ovrl2);
	friend Fraction operator+ (const Fraction& ovrl1, const Fraction& ovrl2);

	Fraction operator+= (const Fraction& ovrl);
	Fraction operator-= (const Fraction& ovrl);
	Fraction operator*= (const Fraction& ovrl);
	Fraction operator/= (const Fraction& ovrl);

	friend bool operator== (const Fraction& ovrl1, const Fraction& ovrl2);
	friend bool operator> (const Fraction& ovrl1, const Fraction& ovrl2);
	friend bool operator< (const Fraction& ovrl1, const Fraction& ovrl2);
	friend bool operator>= (const Fraction& ovrl1, const Fraction& ovrl2);
	friend bool operator<= (const Fraction& ovrl1, const Fraction& ovrl2);
	friend bool operator!= (const Fraction& ovrl1, const Fraction& ovrl2);

	explicit operator float() {
		float a = numerator; float b = denaminator;
		return ((float)(a / b));
	};
	explicit operator double() {
		float a = numerator; float b = denaminator;
		return ((double)(a / b));
	};
};
