# Complex numbers library 
 
This project provides an ADT for the complex numbers, the class Complex. It allows performing arithmetic operations on complex numbers such as addition, subtraction, multiplication and division through overloaded operators for the ease of use. Operations can be performed on complex numbers with complex numbers or with primitive data types such as double. For example, the following statements are valid:
double d = 5.214;
Complex z1, z2(2, -3.2), z3(3, 4);
z1 = (2 + z2) / ((z4 * d)+2*z3);
The Complex class also has methods for integer exponentiation and taking the nth roots. You can read/print a Complex the same way you can a primitive type variable. The insertion(<<) and extraction(>>) operators are overloaded so as to print Complex objects to output streams like cout and to read them from input streams like cin. Other methods for calculating the modulus, the radian angle and the degree angle exist. Therefore, Complex objects can be printed either in the rectangular form (a + bi), trigonometric form (r(cosΘ + i sinΘ)) or exponential (Euler’s) form (r e^Θi).
