#include <iostream>
#include <istream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "complex.h"

using namespace std;



bool operator== (const Complex& c1, const Complex& c2) {
	double c1_real = c1.get_real();
	double c2_real = c2.get_real();
	double c1_imag = c1.get_imag();
	double c2_imag = c2.get_imag();

	double dif_real = abs(c1_real - c2_real);
	double dif_imag = abs(c1_imag - c2_imag);
	if (dif_real < .001 && dif_imag < .001){
		return true;
	}
	else{
		return false;
	}

}

bool operator!= (const Complex& c1, const Complex& c2){
	double c1_real = c1.get_real();
	double c1_imag = c1.get_imag();
	double c2_real = c2.get_real();
	double c2_imag = c2.get_imag();
	if (c1_real != c2_real || c1_imag != c2_imag){
		return true;
	}
	else{
		return false;
	}
}
/*
    * Outputting a `Complex` instance, while illustrating some of the
    * capabilities of I/O streams: `setprecision` gives us a fixed
    * number of decimal places, while `showpos` turns on the plus
    * sign for positive numbers.
    * */
ostream& operator<< (ostream& os, const Complex& c) {
	os << "Real: "<<setprecision(10) << c.real << " Imaginary: " <<setprecision(10)<< c.imag << endl;
	return os;
}

/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	cout << "Input real: ";
	is >> c.real;
	cout << "Input imaginary: ";
	is >> c.imag;
	return is;
}


Complex::operator bool() const {
	if (real == 0 || imag == 0){
		return true;
	}
	else{
		return false;
	}
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	Complex temp = real;
	real ++;
	return temp;
}
/*
     * This overload is pre-decrement: pretty straightforward:
     * decrease the `real` member, and return myself.
     * Of course, it's not obvious that this is what decrementing
     * a complex number *should* do: but we are teaching here,
     * not writing a production Complex class.
     * */
Complex& Complex::operator--(){
	--real;
	return *this;
}

    /*
     * Post-decrement is more complicated than pre: first
     * of all, it takes a dummy int parameter (unused)
     * just so the compiler can tell which inc operator is which.
     * Secondly, since it returns the value from *before*
     * the decrement, we must store that in a temp var.
     * */
Complex Complex::operator--(int dummy){
	Complex val = real--;
	return val;
}
Complex operator+(const Complex& c1, const Complex& c2) {
	double c1_real = c1.get_real();
	double c1_imag = c1.get_imag();
	double c2_real = c2.get_real();
	double c2_imag = c2.get_imag();
	Complex sum = Complex(c1_real + c2_real, c1_imag + c2_imag);
	return sum;

}

Complex operator-(const Complex& c1, const Complex& c2) {
	double c1_real = c1.get_real();
	double c1_imag = c1.get_imag();
	double c2_real = c2.get_real();
	double c2_imag = c2.get_imag();
	Complex diff = Complex(c1_real - c2_real, c1_imag - c2_imag);
	return diff;

}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex Complex::operator*(const int i) {
	return real * i;

}
Complex& Complex::operator -=(const Complex& c1 ){
	double c1_real = c1.get_real();
	double c1_imag = c1.get_imag();
	real -= c1_real;
	imag -= c1_imag;
	return *this;
}

Complex& Complex::operator +=(const Complex&c1){
	double c1_real = c1.get_real();
	double c1_imag = c1.get_imag();
	real += c1_real;
	imag += c1_imag;
	return *this;
}
