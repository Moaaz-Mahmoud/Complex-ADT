This project provides an ADT for the complex numbers, it provides facilities
to perform arithmetic operations such as addition, subtraction, 
multiplication and division through overloaded operators for the ease of use.
Operations can be performed on complex numbers with complex numbers or with
primitive data types such as double, for example, the following statements
are valid: 
double d = 5.214; Complex z1, z2(2, -3.2), z3(3, 4); 
z1 = (2 + z2) / (z4 * d);

The Complex class also has operations like raising to integer exponent
or taking the nth root.

Facilities for printing and reading to and from streams are also available.
The insertion(<<) and extraction(>>) operators are overloaded so as to print
Complex objects to output streams like cout and to read them from input 
streams like cin.

Other methods for calculating the modulus, the radian angle and the degree
angle exist, therefore, Complex objects can be printed either in the 
rectangular form (a + bi), trigonometric form (r(cosΘ + i sinΘ)) or
exponential (Euler’s) form (r eiΘ).
