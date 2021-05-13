#pragma once
#include<iostream>
#include<string>

class Overload {
private:
	int numerator, denaminator;
	friend std::ostream& operator<< (std::ostream& out, const Overload& ovrl);
	friend std::istream& operator>> (std::istream& in, Overload& ovrl);
public:
	Overload();
	Overload(int a1, int b1);
	Overload(const Overload& lnk);
	Overload(Overload&& llnk);

	Overload operator= (Overload ovrl);

	friend Overload operator* (const Overload& ovrl1, const Overload& ovrl2);
	friend Overload operator/ (const Overload& ovrl1, const Overload& ovrl2);
	friend Overload operator- (const Overload& ovrl1, const Overload& ovrl2);
	friend Overload operator+ (const Overload& ovrl1, const Overload& ovrl2);

	Overload operator+= (const Overload& ovrl);
	Overload operator-= (const Overload& ovrl);
	Overload operator*= (const Overload& ovrl);
	Overload operator/= (const Overload& ovrl);

	friend bool operator== (const Overload& ovrl1, const Overload& ovrl2);
	friend bool operator> (const Overload& ovrl1, const Overload& ovrl2);
	friend bool operator< (const Overload& ovrl1, const Overload& ovrl2);
	friend bool operator>= (const Overload& ovrl1, const Overload& ovrl2);
	friend bool operator<= (const Overload& ovrl1, const Overload& ovrl2);
	friend bool operator!= (const Overload& ovrl1, const Overload& ovrl2);

	explicit operator float() {
		float a = numerator; float b = denaminator;
		return ((float)(a / b));
	};
	explicit operator double() {
		float a = numerator; float b = denaminator;
		return ((double)(a / b));
	};
};
