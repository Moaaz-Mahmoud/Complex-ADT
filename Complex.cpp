/* The Complex class.cpp
   The driver for the Complex library.
*/

#include "Complex.h"
#define TESTING 0		//Set this flag to 1 to enable testing
						//or to 0 to disable.

Complex z1(-3, -4), z2, z3;
//Unit testing.
#if TESTING	
void testBasic();
void testArith_Com_typ();
void testArith_typ_Com();
void testRelational();
void testPowRt();
void testExcept();
void testform();
//Integration testing.
void IntegrationTesting();
#endif

int main()
{
#if TESTING
	printf_s("  %c  Unit testing\n\n\n", 254);
	testBasic();
	testArith_Com_typ();
	testArith_typ_Com();
	testRelational();
	testPowRt();
	testExcept();
	testform();

	std::cout
		<< "\n\n*********************************************\n\n\n\n\n";

	printf_s("  %c  Integration testing\n\n\n", 254);
	IntegrationTesting();
#endif

	system("pause"); return 0;
}

#if TESTING
void testBasic() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Basic operations( Printing, reading"
		<< "and arithmetic(Complex with Complex) ) :-\n\n";
	std::cout << ">>> "; std::cin >> z2;
	z3 = z1 + z2;
	z3 = z1 + z2; std::cout << "z1 + z2 = " << z3 << '\n';
	z3 = z1 - z2;
	std::cout << "z1 - z2 = " << z3 << '\n';
	z3 = z1 * z2;
	std::cout << "z1 * z2 = " << z3 << '\n';
	z3 = z1 / z2;
	std::cout << "z1 / z2 = " << z3 << '\n';
	z3 = z1.conjugate();
	std::cout
		<< "z1 radian angle : " << z1.rad_angle() << '\n'
		<< "z1 degree angle : " << z1.deg_angle() << '\n'
		<< "z1 magnitude    : " << z1.get_magnitude() << '\n'
		<< "z1 conjugate    : " << z3 << "\n\n\n";
}
void testArith_Com_typ() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Arithmetic operators(Complex with othe datatypes) :-\n\n";
	z3 = z1 + 2;
	std::cout << "z1 + 2 = " << z3 << '\n';
	z3 = z1 - 2;
	std::cout << "z1 - 2 = " << z3 << '\n';
	z3 = z1 * 2;
	std::cout << "z1 * 2 = " << z3 << '\n';
	z3 = z1 / 2;
	std::cout << "z1 / 2 = " << z3 << "\n\n\n";
}
void testArith_typ_Com() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Arithmetic operators(Other datatypes with Complex) :-\n\n";
	z3 = 4 + z1;
	std::cout << "4 + z1 = " << z3 << '\n';
	z3 = 4 - z1;
	std::cout << "4 - z1 = " << z3 << '\n';
	z3 = 4 * z1;
	std::cout << "4 * z1 = " << z3 << '\n';
	z3 = 4 / z1;
	std::cout << "4 / z1 = " << z3 << "\n\n\n";
}
void testRelational() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Relational operators :-\n\n";
	z1.set(3.3, 4.4);
	z2.set(3.3, 4.4);
	z3.set(2, 2);
	if (z1 == z2)
		std::cout << "z1 and z2 are equal\n";
	else
		std::cout << "z1 and z2 are not equal\n";
	if (z1 == z3)
		std::cout << "z1 and z3 are equal";
	else
		std::cout << "z1 and z3 are not equal";
	std::cout << "\n\n\n";
}
void testPowRt() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Power and roots :-\n\n";
	z3 = z1.power(4);
	std::cout
		<< "z1 ^ 4 = " << z3 << '\n'
		<< "z1 4th roots:-\n";
	Complex* ptr = z1.root(4);
	for (int i = 0; i < 4; i++)
		std::cout << *ptr++ << '\n';
	std::cout << "\n\n";
}
void testExcept() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Exception classes :-\n"
		<< char(254) << "The exception class zero_div\n"
		<< "__Should be thrown only once__.\n\n";
	// Should be thrown here.
	try {
		z3 = z1 / 0;
		std::cout << "z3 = " << z3 << "\n\n\n";
	}
	catch (Complex::zero_div) {}
	// Shouldn't be thrown here.
	try {
		z3 = z1 / 2;
		std::cout << "z3 = " << z3 << "\n\n\n";
	}
	catch (Complex::zero_div) {}

	Complex z0(0, 0);
	std::cout << z0.rad_angle() << '\n';
	std::cout << z0.deg_angle() << '\n';
	z0.set(0, 1);
	std::cout << z0.rad_angle();
	std::cout << z0.deg_angle();

	z3.set(0, 4, POL);
	std::cout << "z3_pol = " << z3 << '\n';
	z3.set(0, 0);
	std::cout << "zero pol = " << z3 << '\n';
	z3.set_form(EXP);
	std::cout << "zero exp = " << z3 << '\n';
	std::cout << "\n\n";
}
void testform() {
	std::cout
		<< ' ' << char(254) << ' '
		<< "Form :-\n\n";
	z1.set_form(POL);
	std::cout << "z1_pol = " << z1 << '\n';
	z1.set_form(EXP);
	std::cout << "z1_exp = " << z1 << '\n';
}

void IntegrationTesting() {
	Complex* ptr;
	z3 = z1 + z2 - 4 * z2 / z1;
	std::cout << "z1 + z2 - 4 * z2 / z1" << z3 << '\n';
	ptr = (z1 + 2 * z2).root(3);
	std::cout << "The cubic roots of z1 + 2 * z2 :-\n";
	for (int i = 0; i < 2; i++)
		std::cout << *ptr++ << '\n';
	std::cout << (z1 + 2 * z2).root(3)[2] << '\n';
	std::cout 
		<< "z1 rad angle : " 
		<< z1.conjugate().conjugate().rad_angle() << '\n';
	z3 = (z2 = z1 + 2) + 2;
	std::cout 
		<< "z1 : " << z1 << "\tz2 : " 
		<< z2 << "\tz3 : " << z3 << '\n';
}

#endif
