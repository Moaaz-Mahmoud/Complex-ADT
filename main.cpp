/* main.cpp
   The driver for the 'Complex' class.
*/

#include "Complex.h"
#include <iomanip>
#define END std::cout << "\n\n___________________________\n\n";
#define TESTING 1		//Set this flag to 1 to enable testing
						//or to 0 to disable.

#if TESTING
void testArithmetic();
void testForm();
void testConjugate();
void testPower();
void testRoots();
void testRelational();
void testAngle();
#endif

int main()
{
	std::cout.setf(std::ios::left);
#if TESTING
	printf("     %c%c%c%c", 254, 254, 254, 254);
	std::cout
		<< "   "
		<< "Welcome to the interactive driver for the "
		<< "ADT Complex!";
	printf("   %c%c%c%c\n", 254, 254, 254, 254);
	std::cout
		<< "To enter a complex number, just enter two\n"
		<< "floating point numbers separated by a space\n";
	testArithmetic();
	testForm();
	testConjugate();
	testPower();
	testRoots();
	testRelational();
	std::cout << "One more time!\n";
	testRelational();
	testAngle();
#endif
	//You can disable testing and insert your
	//own statements here!
}

#if TESTING
void testArithmetic() {
	Complex z1, z2, z3;
	std::cout << char(254) << "  "
		<< "Enter two complex numbers to receive their\n"
		<< "sum, difference, product and quotient.\n"
		<< ">>> ";
	std::cin >> z1 >> z2;
	z3 = z1 + z2;
	std::cout << std::setw(12) << "Sum: " << z3 << '\n';
	z3 = z1 - z2;
	std::cout << std::setw(12) << "Difference: " << z3 << '\n';
	z3 = z1 * z2;
	std::cout << std::setw(12) << "Product: " << z3 << '\n';
	if (z2.get_magnitude()) {
		z3 = z1 / z2;
		std::cout 
			<< std::setw(12) << "Quotient: "
			<< z3 << '\n';
	}
	else {
		std::cout << "Can't divide by zero!\n";
	}
	END
}
void testForm() {
	Complex z;
	std::cout << char(254) << "  "
		<< "Enter a complex number to display it in\n"
		<< "the rectangular, polar and exponential\n"
		<< "forms\n"
		<< ">>> ";
	std::cin >> z;
	std::cout << z << '\n';
	z.set_form(POL);
	std::cout << z << '\n';
	z.set_form(EXP);
	std::cout << z << '\n';
	END;
}
void testConjugate() {
	Complex z;
	std::cout << char(254) << "  "
		<< "Enter a complex number to display its\n"
		<< "conjugate\n"
		<< ">>> ";
	std::cin >> z;
	Complex z_ = z.conjugate();
	std::cout << z_ << '\n';
	END;
}
void testPower() {
	Complex z;
	int n;
	std::cout << char(254) << "  "
		<< "Now, let's find z raised to the power of n\n"
		<< "Enter z\n>>> ";
	std::cin >> z;
	std::cout << "Enter n\n>>> ";
	std::cin >> n;
	Complex Z = z.power(n);
	std::cout << Z << '\n';
	END;
}
void testRoots() {
	Complex z, *Z;
	int n;
	std::cout << char(254) << "  "
		<< "Now, let's find the nth roots of z\n"
		<< "Enter z\n>>> ";
	std::cin >> z;
	std::cout << "Enter n\n>>> ";
	std::cin >> n;
	Z = z.root(n);
	std::cout << "Here are the nth roots:\n";
	for (int i = 0; i < n; i++) {
		std::cout << Z[i] << '\n';
	}
	delete[] Z;
	END;
}
void testRelational() {
	Complex z1, z2;
	std::cout << char(254) << "  "
		<< "Enter two complex numbers z1\n"
		<< "and z2 to check whether they're\n"
		<< "equal\n"
		<< ">>> ";
	std::cin >> z1 >> z2;
	if (z1 == z2)
		std::cout << "The two numbers are equal!\n";
	else
		std::cout << "The two numbers are not equal!\n";
	END;
}
void testAngle() {
	Complex z;
	std::cout << char(254) << "  "
		<< "Enter a complex number to find\n"
		<< "its argument in radians and degrees\n";
	std::cin >> z;
	std::cout
		<< std::setw(10) 
		<< "Radians:" << z.rad_angle() << '\n'
		<< std::setw(10) 
		<< "Degrees:" << z.deg_angle() << '\n';
	END;
}
#endif
