#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "StdAfx.h"
#include "Complex.h"
#include <iostream>
#include <cmath>
const float PI = 3.14159;

enum form_t {REC, POL, EXP};
class Complex
{
	//Data members.
	float real;
	float imaginary;
protected:
	//Private member functions.
	void  get();
	void  showREC()			const;
	void  showPOL()			const;
	void  showEXP()			const;
	Complex divide_by(Complex);
	//template <class T> friend Complex divide_by(Complex, T)	;	//-----------------delete me--------------
	float calculate_angle() const;
public:
	//Data members.
	mutable form_t form;
	//No-arg constructor
	Complex() : real(0), imaginary(0), form(REC) {}
	//Two-arg constructor
	Complex(float x, float y, form_t c = REC) : real(x), imaginary(y), form(c) {}
	//virtual destructor
	virtual ~Complex() {}
	//set and get
	void  set(float x, float y, form_t c = REC);
	void  set_form(form_t c);
	float get_real();
	float get_imaginary();
	//Basic member functions
	float rad_angle()	  const;
	float deg_angle()	  const;
	float get_magnitude() const;
	Complex conjugate()   const;
	//Insertion '<<' and extraction '>>' operators
	friend std::istream& operator >> (std::istream& s, Complex& C);
	friend std::ostream& operator << (std::ostream& s, Complex& C);
	//Operators (Complex with Complex)
	Complex operator + (Complex c);
	Complex operator - (Complex c);
	Complex operator * (Complex c);
	Complex operator / (Complex c);
	//Operators (Complex with other datatypes)
	template <class T>
	Complex operator + (T num) {
	Complex sum;
	sum.real = real + num;
	sum.imaginary = imaginary;
	sum.set_form(form);
	return sum;
	}
	template <class T>
	Complex operator - (T num) {
	Complex difference;
	difference.real = real - num;
	difference.imaginary = imaginary;
	difference.set_form(form);
	return difference;
	}
	template <class T>
	Complex operator * (T num) {
	Complex product;
	product.real = real * num;
	product.imaginary = imaginary * num;
	product.set_form(form);
	return product;
}
	template <class T>
	Complex operator / (T num) {
		Complex quotient(0,0);
		Complex Num(num, 0);
		try{
			quotient = this->divide_by(Num);
		}
		catch(Complex::zero_div()) {}
		return quotient;
	}
	//Operators (Other datatypes with Complex)
	template <class T>
	friend Complex operator + (T num, Complex C){
	return C + num;
	}
	template <class T>
	friend Complex operator - (T num, Complex C) {
	return (C - num) * (-1);
	}
	template <class T>
	friend Complex operator * (T num, Complex C) {
	return C * num;
	}
	template <class T>
	friend Complex operator / (T num, Complex C) {
	float x, y;
	Complex pre_result;
	if (C.get_real() == 0 && C.get_imaginary() == 0)
		throw Complex::zero_div();
	x = C.get_real() / (pow(C.get_real(), 2) + pow(C.get_imaginary(), 2));
	y = -C.get_imaginary() / (pow(C.get_real(), 2) + pow(C.get_imaginary(), 2));
	pre_result.set(x, y);
	return num * pre_result;
	}
	//Relational operators ('==' and '!=')
	bool operator == (Complex C);
	bool operator != (Complex C);
	//Power and roots
	Complex power(int n);
	Complex *root(const int k);
	//Exception classes
	class zero_div {
	public:
		zero_div() {
			std::cout 
				<< " *** An exception was thrown due to an attempt\n"
				<< "     to divide by zero. ***\n";
		}
	}; //end zero_div
	class unspec_ang {
	public:
		unspec_ang() {
			std::cout
				<< "*** Unspecified angle ***\n";
		}
	};
}; //end Complex

#endif
