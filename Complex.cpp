/* Complex.cpp
   Implements the Complex class.
*/
#include "stdafx.h"
#include "Complex.h"

using std::cin; using std::cout;
using std::string;
using std::istream; using std::ostream;

//Basic member functions.
void  Complex::get() {
	cin >> real >> imaginary;
}
float Complex::get_real() {
	return real;
}
float Complex::get_imaginary() {
	return imaginary;
}
void  Complex::set(float x, float y, form_t c) {
	real = x;
	imaginary = y;
}
void  Complex::set_form(form_t f){ 
	form = f;
}
void  Complex::showREC()		 const {
	cout << '(';
	if (real > 0)
		if (imaginary > 0)	//_________________________a + bi
			cout << real << " + " << imaginary << 'i';
		else if (imaginary == 0)	//_____________________a
			cout << real;
		else	//_____________________________________a-bi
			cout << real << " - " << -imaginary << 'i';
	else if (real == 0)
		if (imaginary > 0)	//_________________________bi
			cout << imaginary << 'i';
		else if (imaginary == 0)	//_____________________0
			cout << '0';
		else	//_____________________________________-bi
			cout << imaginary << 'i';
	else //real < 0
		if (imaginary > 0)	//_________________________-a+bi
			cout << real << " + " << imaginary << 'i';
		else if (imaginary == 0)	//_____________________-a
			cout << real;
		else	//_____________________________________-a-bi
			cout << real << " - " << -imaginary << 'i';
	cout << ')';
}
void  Complex::showPOL()		 const{
	float r = sqrt( pow(real, 2) + pow(imaginary, 2) );
	float theta;
	try {
	theta = this->calculate_angle();
	}
	catch (Complex::unspec_ang) {
		theta = 0;
		goto a;
	}
	a: std::cout << "(" << r << ", " << theta << ")";
}
void  Complex::showEXP()		 const{
	float r = sqrt( pow(real, 2) + pow(imaginary, 2) );
	float theta;
	try {
	theta = this->calculate_angle();
	}
	catch (Complex::unspec_ang) {
		theta = 0;
		goto b;
	}
	b: std::cout << "(" << r << "e^(" << theta << "i))";
}
Complex Complex::divide_by(Complex c) {
	Complex quotient;
	float den;		//common denominator c^2 + d^2
	if (c.get_real() == 0 && c.get_imaginary() == 0)
		throw Complex::zero_div();
	den = pow(c.real, 2) + pow(c.imaginary, 2);
	quotient.real = (real * c.real + imaginary * c.imaginary) / den;
	quotient.imaginary = (imaginary * c.real - real * c.imaginary) / den;
	quotient.set_form(form);
	return quotient;
}
float Complex::calculate_angle() const{
		if(real > 0)									//////
		if(imaginary > 0)								//////
			return atan(imaginary / real);				//////
		else if(!imaginary)								//////
			return 0;									//////
		else											//////
			return -atan(abs(imaginary) / abs(real));	//////
	else if(!real)							//////
		if(imaginary > 0)					//////
			return PI/2;					//////
		else if(!imaginary)					//////
			throw Complex::unspec_ang();	//////
		else								//////
			return 3*PI/2;					//////
	else													//////
		if(imaginary > 0)									//////
			return PI - atan(abs(imaginary) / abs(real));	//////
		else if(!imaginary)									//////
			return PI;										//////
		else												//////
			return PI + atan(abs(imaginary) / abs(real));	//////
}
float Complex::rad_angle()       const {
	try {
		return this->calculate_angle();
	}
	catch (Complex::unspec_ang) {}
}
float Complex::deg_angle()       const {
	return (180/PI) * this->rad_angle();
}
float Complex::get_magnitude()   const {
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}
Complex Complex::conjugate()     const {
	Complex con = *this;
	con.imaginary = -(con.imaginary);
	con.set_form(form);
	return con;
}
//Complex operators (Complex with Complex).
Complex Complex::operator + (Complex c)
{
	Complex sum;
	sum.real = real + c.real;
	sum.imaginary = imaginary + c.imaginary;
	sum.set_form(form);
	return sum;
}
Complex Complex::operator - (Complex c)
{
	Complex difference;
	difference.real = real - c.real;
	difference.imaginary = imaginary - c.imaginary;
	difference.set_form(form);
	return difference;
}
Complex Complex::operator * (Complex c)
{
	Complex product;
	product.real = real * c.real - imaginary * c.imaginary;
	product.imaginary = real * c.imaginary + imaginary * c.real;
	product.set_form(form);
	return product;
}
Complex Complex::operator / (Complex c)
{
	Complex quotient;
	try{
		quotient = this->divide_by(c);
	}
	catch(Complex::zero_div()){}
	return quotient;
}
//Complex operators (Complex with other datatypes) --> Defined in the header.
//Operators (Other datatypes with Complex) ----------> Defined in the header.
//Insertion '<<' and extraction '>>' operators.
istream & operator >> (istream& s, Complex& C) {
	C.get();
	return s;
}
ostream& operator << (ostream& s, Complex& C) {
	switch(C.form) {
	case REC: C.showREC(); break;
	case POL: C.showPOL(); break;
	case EXP: C.showEXP(); break;
	}
	return s;
}
//Relational operators ('==' and '!=')
bool Complex::operator == (Complex C) {
	return (real == C.get_real()) && (imaginary == C.get_imaginary());
}
bool Complex::operator != (Complex C) {
	return !((*this) == C);
}
//Power and roots.
Complex Complex::power(int n) {
	Complex result;
	float r = pow(this->get_magnitude(), n);
	float theta = this->rad_angle() * n;
	result.set(r * cos(theta), r * sin(theta));
	result.set_form(form);
	return result;
}
Complex *Complex::root(const int k) {
	Complex* results;
	results = new Complex[k];
	for (int i = 0; i < k; i++) {
		results[i].set(
			pow(this->get_magnitude(), 1 / static_cast<float>(k))* cos((this->rad_angle() + 2 * PI * (i - 1)) / static_cast<float>(k)),
			pow(this->get_magnitude(), 1 / static_cast<float>(k))* sin((this->rad_angle() + 2 * PI * (i - 1)) / static_cast<float>(k))
		);
		results[i].set_form(form);
	}
	return results;
}
