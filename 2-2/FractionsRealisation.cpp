#include "Fractions.h"

int inPow(int numb, int pow) {
	int nsave = numb;
	for (int i = 1; i < pow; i++) {
		numb *= nsave;
	}
	return numb;
}

int nod(int a, int b) {
	a = abs(a); b = abs(b);
	if (a == b) return a;
	if (a > b) return nod(a - b, b);
	return nod(a, b - a);
}

int nok(int a, int b) {
	return a * b / nod(a, b);
}

Fraction::Fraction() {
	numerator = 0; denaminator = 1;
};

Fraction::Fraction(int a1, int b1) {
	numerator = a1; denaminator = b1;
};

Fraction::Fraction(const Fraction& lnk) {
	numerator = lnk.numerator; denaminator = lnk.denaminator;
};

Fraction::Fraction(Fraction&& llnk) {
	numerator = llnk.numerator; denaminator = llnk.denaminator;
};

std::ostream& operator<< (std::ostream& out, const Fraction& ovrl) {
	out << ovrl.numerator << " / " << ovrl.denaminator << std::endl;
	return out;
};

std::istream& operator>> (std::istream& in, Fraction& ovrl) {
	std::string inp, num1 = "", den1 = ""; int posit = 0;
	in >> inp;

	if (inp.find('/') == -1) inp += "/1";

	while (inp[posit] != '/') {
		num1 += inp[posit]; posit++;
	}
	ovrl.numerator = atoi(num1.c_str());
	posit++;
	while (posit < inp.size()) {
		den1 += inp[posit]; posit++;
	}
	ovrl.denaminator = atoi(den1.c_str());
	return in;
};

Fraction operator* (const Fraction& ovrl1, const Fraction& ovrl2) {
	int numer, denam, noD;
	numer = (ovrl1.numerator * ovrl2.numerator);
	denam = (ovrl1.denaminator * ovrl2.denaminator);
	noD = nod(numer, denam);
	return Fraction(numer / noD, denam / noD);
};

Fraction operator/ (const Fraction& ovrl1, const Fraction& ovrl2) {
	int numer, denam, noD;
	numer = (ovrl1.numerator * ovrl2.denaminator);
	denam = (ovrl1.denaminator * ovrl2.numerator);
	noD = nod(numer, denam);
	return Fraction(numer /= noD, denam /= noD);
};

Fraction operator- (const Fraction& ovrl1, const Fraction& ovrl2) {
	int numer, denam, noD, noK;
	noK = nok(ovrl1.denaminator, ovrl2.denaminator);
	numer = ((ovrl1.numerator * (noK / ovrl1.denaminator) - (ovrl2.numerator * (noK / ovrl2.denaminator))));
	denam = noK;
	noD = nod(numer, denam);
	return Fraction(numer /= noD, denam /= noD);
};

Fraction operator+ (const Fraction& ovrl1, const Fraction& ovrl2) {
	int numer, denam, noD, noK;
	noK = nok(ovrl1.denaminator, ovrl2.denaminator);
	numer = ((ovrl1.numerator * (noK / ovrl1.denaminator) + (ovrl2.numerator * (noK / ovrl2.denaminator))));
	denam = noK;
	noD = nod(numer, denam);
	return Fraction(numer /= noD, denam /= noD);
};

Fraction Fraction::operator= (Fraction ovrl) {
	this->numerator = ovrl.numerator;
	this->denaminator = ovrl.denaminator;
	return *this;
}

Fraction Fraction::operator+=(const Fraction& ovrl)
{
	operator=(operator+(*this, ovrl));
	return *this;
}

Fraction Fraction::operator-=(const Fraction& ovrl)
{
	operator=(operator-(*this, ovrl));
	return *this;
}


Fraction Fraction::operator*=(const Fraction& ovrl)
{
	operator=(operator*(*this, ovrl));
	return *this;
}

Fraction Fraction::operator/=(const Fraction& ovrl)
{
	operator=(operator/(*this, ovrl));
	return *this;
}

bool operator== (const Fraction& ovrl1, const Fraction& ovrl2) {		
	return ((double)(ovrl1.numerator / ovrl1.denaminator) == (double)(ovrl2.numerator / ovrl2.denaminator));
};

bool operator> (const Fraction& ovrl1, const Fraction& ovrl2) {		
	return ((double)(ovrl1.numerator / ovrl1.denaminator) > (double)(ovrl2.numerator / ovrl2.denaminator));
};

bool operator< (const Fraction& ovrl1, const Fraction& ovrl2) {		
	return ((double)(ovrl1.numerator / ovrl1.denaminator) < (double)(ovrl2.numerator / ovrl2.denaminator));
};

bool operator>= (const Fraction& ovrl1, const Fraction& ovrl2) {		
	return ((double)(ovrl1.numerator / ovrl1.denaminator) >= (double)(ovrl2.numerator / ovrl2.denaminator));
};

bool operator<= (const Fraction& ovrl1, const Fraction& ovrl2) {
	return ((double)(ovrl1.numerator / ovrl1.denaminator) <= (double)(ovrl2.numerator / ovrl2.denaminator));
};

bool operator!= (const Fraction& ovrl1, const Fraction& ovrl2) {
	return ((double)(ovrl1.numerator / ovrl1.denaminator) != (double)(ovrl2.numerator / ovrl2.denaminator));
};
