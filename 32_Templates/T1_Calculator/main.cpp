#include <iostream>
#include "Calculator.h"
#include "ComplexNr.h"

int main()
{
	
	// Create an instance of the Calculator class
	Calculator<double, double, int> calculator;

	// Test the add function
	double result = calculator.add(3.5, 2);
	std::cout << "Normal addition result: " << result << std::endl;

	// Test the subtract function
	result = calculator.subtract(5.8, 2);
	std::cout << "Normal subtraction result: " << result << std::endl;

	// Test the multiply function
	result = calculator.multiply(2.5, 4);
	std::cout << "Normal multiplication result: " << result << std::endl;

	// Test the divide function
	result = calculator.divide(900, 3);
	std::cout << "Normal division result: " << result << std::endl;

	// Create an instance of the ComplexNr class
	ComplexNr<double> complexNumber;
	complexNumber.real = 2.5;
	complexNumber.imaginary = 3.7;
	
	// Create another instance of the Calculator class for complex numbers
	Calculator<ComplexNr<double>, ComplexNr<double>, int> complexCalculator;

	// Test the add function for complex numbers
	ComplexNr<double> complexResult = complexCalculator.add(complexNumber, 2);
	std::cout << "Complex + real addition result: " << complexResult.real << " + " << complexResult.imaginary << "i" << std::endl;

	// Test the subtract function for complex numbers
	complexResult = complexCalculator.subtract(complexNumber, 2);
	std::cout << "Complex + real subtraction result: " << complexResult.real << " + " << complexResult.imaginary << "i" << std::endl;
	
	// Test the multiply function for complex numbers
	complexResult = complexCalculator.multiply(complexNumber, 2);
	std::cout << "Complex + real multiplication result: " << complexResult.real << " + " << complexResult.imaginary << "i" << std::endl;

	// Test the divide function for complex numbers
	complexResult = complexCalculator.divide(complexNumber, 2);
	std::cout << "Complex + real division result: " << complexResult.real << " + " << complexResult.imaginary << "i" << std::endl;

	// Create instances of ComplexNr
	ComplexNr<int> num1;
	num1.real = 3;
	num1.imaginary = 4;
	ComplexNr<double> num2;
	num2.real = 2.5;
	num2.imaginary = 1.5;
	
	// Create an instance of the Calculator class
	Calculator<ComplexNr<int>, int, ComplexNr<int>> calc1;
	Calculator<ComplexNr<double>, ComplexNr<int>, ComplexNr<double>> calc2;

	// Perform calculations using the add function
	ComplexNr<int> result1 = calc1.add(5, num1);
	ComplexNr<double> result2 = calc2.add(num1, num2);

	// Print the results
	std::cout << "Real + complex addition result: " << result1.real << " + " << result1.imaginary << "i" << std::endl;
	std::cout << "Complex only addition result: " << result2.real << " + " << result2.imaginary << "i" << std::endl;

	// Perform calculations using the subtract function
	result1 = calc1.subtract(5, num1);
	result2 = calc2.subtract(num1, num2);

	// Print the results
	std::cout << "Real + complex subtract result: " << result1.real << " + " << result1.imaginary << "i" << std::endl;
	std::cout << "Complex only subtract result: " << result2.real << " + " << result2.imaginary << "i" << std::endl;

	// Perform calculations using the multiply function
	result1 = calc1.multiply(5, num1);
	result2 = calc2.multiply(num1, num2);

	// Print the results
	std::cout << "Real + complex multiplication result: " << result1.real << " + " << result1.imaginary << "i" << std::endl;
	std::cout << "Complex only multiplication result: " << result2.real << " + " << result2.imaginary << "i" << std::endl;

	// Perform calculations using the divide function
	result1 = calc1.divide(5, num1);
	result2 = calc2.divide(num1, num2);

	// Print the results
	std::cout << "Real + complex division result: " << result1.real << " + " << result1.imaginary << "i" << std::endl;
	std::cout << "Complex only division result: " << result2.real << " + " << result2.imaginary << "i" << std::endl;

	return 0;
}