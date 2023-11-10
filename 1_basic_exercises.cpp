#include <iostream>
#include <math.h>
#include <algorithm>
#include<string>
#include<vector>
#include <bitset>
using namespace std;

//Implement the Pythagorean theorem and display the length of hypotenuse, using the value of the other 2 sides received as input.
void ex4() {

	double cathetus1, cathetus2, hypotenuse;

	cathetus1 = 3;
	cathetus2 = 4;
	cout << "Enter the cat 1: ";
	cin >> cathetus1;

	cout << "Enter the cat 2: ";
	cin >> cathetus2;

	hypotenuse = sqrt(pow(cathetus1, 2) + pow(cathetus2, 2));

	cout << "The hypo is: " << hypotenuse << endl;
}

//Read an integer and display “even” if its divisible by 2 or “odd” if not.
void ex5() {

	int var;

	cin >> var;

	if (var % 2 == 0)
		cout << "The n is even" << endl;
	else
		cout << "The n is odd" << endl;

}

//Compute the maximum of 3 numbers received as input.
void ex6() {

	int nr1, nr2, nr3, max;

	cout << "nr1= ";
	cin >> nr1;
	cout << endl;
	cout << "nr2= ";
	cin >> nr2;
	cout << endl;
	cout << "nr3= ";
	cin >> nr3;
	cout << endl;

	max = nr1;

	if (nr2 > max)
		max = nr2;

	if (nr3 > max)
		max = nr3;

	cout << max;
}

//Sort 5 numbers received as input in ascending order.
void ex7() {

	int arr[5];
	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "]=";
		cin >> arr[i];
		cout << endl;
	}
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);

	cout << "The numbers in ascending order are: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

//Sum of first 100 numbers
void ex8() {

	int n = 100;
	int sum = n * (n + 1) / 2;
	cout << sum;

}

//Product of first n numbers n=20
void ex9a() {

	long long product = 1;

	for (int i = 1; i <= 40; i += 2) {
		product *= i;
	}

	cout << "The product of the first 20 odd numbers is: " << product << endl;


}

//multiply two extra long numbers
string multiply(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0 || len2 == 0)
		return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(len1 + len2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1
	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;

		// Go from right to left in num2            
		for (int j = len2 - 1; j >= 0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum / 10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
		return "0";

	// generate the result string
	string s = "";

	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

//Product of first n numbers n=any value
void ex9b() {

	string Product = "1";
	string converted;

	for (int i = 1; i <= 5000; i = i + 2)
	{
		converted = to_string(i);
		Product = multiply(Product, converted);
	}

	cout << Product;
}

//Check if a number is prime (a number is prime if its divisible only by 1 and itself).
void ex10() {

	int val;
	bool isprime = 1;
	cout << "Enter a number to check if it is prime or not: ";
	cin >> val;
	cout << endl;

	float val_sqrt = sqrt(val);
	int val_sqrt_int_aprox = val_sqrt + 1;

	for (int i = 2; i <= val_sqrt_int_aprox; i++)
	{
		if (val % i == 0)
			isprime = false;
	}

	if (isprime == true)
		cout << "The number is prime" << endl;
	else
		cout << "The number is not prime" << endl;
}

//Display all divisors of a number.
void ex11() {

	int nr;
	cout << "Enter a number to print all its divisors: ";
	cin >> nr;
	cout << endl;

	for (int i = 1; i <= sqrt(nr); i++)
	{
		if (nr % i == 0)
			if (i != nr / i)
				cout << i << " " << nr / i << " ";
			else
				cout << i << " ";
	}
}

//Compute the factorial of any number received as input using while.
void ex12() {

	int nr;
	cout << "Enter a number to compute the factorial: ";
	cin >> nr;
	cout << endl;

	string factorial = "1";
	string converted;
	int i = 1;

	while (i <= nr)
	{
		converted = to_string(i);
		factorial = multiply(factorial, converted);
		i = i + 1;
	}

	cout << "The factorial of " << nr << " is: " << factorial;

}

//computes the factorial of a nr recursively
int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);

}

//Compute the factorial of any number received as input using recursive functions.
void ex13() {

	int nr;
	cout << "Enter a number to compute the factorial: ";
	cin >> nr;
	cout << endl;
	cout << "The factorial of " << nr << " is: " << factorial(nr);
}

//Sort an array of N elements in descending order.
void ex14() {

	int len;
	int arr[100];
	int x;
	bool swapped;

	cout << "Enter the length of the array: ";
	cin >> len;
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
		cout << endl;
	}

	for (int i = 0; i < len - 1; i++) {
		swapped = false;
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}

	cout << "The array sorted in descending order is: ";

	for (int i = 0; i < len; i++)
	{
		cout << " arr[" << i << "]= " << arr[i];
	}
}

//Display the minimum of N numbers, the numbers are in a random order.
void ex15() {

	int min = INT_MAX;
	int len;
	int arr[100];

	cout << "Enter the length of the array: ";
	cin >> len;
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
		cout << endl;
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}

	cout << "The minim is:" << min;
}

//Read N numbers and display the numbers and the longest sequence of numbers sorted in ascending order. Ex: 1, 2, 6, 4, 5, 8, 9, 1, 25, 13, 14, 12 = > {4, 5, 8, 9}
void ex16() {

	int firstNr;
	int n;
	int arr[100];
	int sequence_len = 1;
	int firstNrPos = 0;
	int savePos;
	int i;

	cout << "Enter the length of the array: ";
	cin >> n;
	cout << endl;

	int max_sequence_len = 0;

	for (i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
		cout << endl;
	}

	firstNr = arr[0];

	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			if (sequence_len > max_sequence_len) {
				max_sequence_len = sequence_len;
			}

			sequence_len = 1;
			firstNr = arr[i + 1];
			firstNrPos = i + 1;
		}
		else {
			sequence_len++;
		}
	}

	if (sequence_len > max_sequence_len) {
		max_sequence_len = sequence_len;
	}

	for (i = firstNrPos; i < firstNrPos + max_sequence_len; i++)
		cout << "arr[" << i << "]= " << arr[i] << endl;

	cout << "The longest sequence has " << max_sequence_len << " elements";
}

//Display the position of the minumum number in an array.
void ex17() {

	int n;
	int arr[100];
	int min = INT_MAX;
	int minPos = 0;

	cout << "Enter the length of the array: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
		cout << endl;

		if (arr[i] < min) {
			min = arr[i];
			minPos = i;
		}

	}

	cout << "the pos of the min nr in the array is: " << minPos;
}

//Convert an integer to binary using only arithmetical operations, ignore leading zeros
void ex18() {

	int x;

	cin >> x;

	string result;

	//your code here

	while (x > 0)
	{
		result = result + to_string(x % 2);
		x = x / 2;
	}

	cout << endl << "result: ";

	for (int i = size(result) - 1; i >= 0; i--)
	{
		cout << result.at(i);
	}
	// you can use bitset to check your result

	// cout << “expected result: “ << bitset<16>(x) << endl;

}

//Convert an integer to hexadecimal, store it in a string and display it
void ex19() {

	int x;

	cin >> x;

	string result;

	// your code here

	while (x > 0)
	{
		if (x % 16 <= 9)
			result = result + to_string(x % 16);
		else
			result = result + char(((x % 16) % 10) + 'a');

		x = x / 16;
	}

	cout << "result: 0x";

	for (int i = size(result) - 1; i >= 0; i--)
	{
		cout << result.at(i);
	}

}

//Computes powers using the mathematical approach
double power(double base, int exponent) {

	if (exponent == 0) {
		return 1;
	}

	double result = power(base, exponent / 2);

	if (exponent % 2 == 0)
		return result * result;
	else
		return base * result * result;
}


//Compute the Nth power of a number and try to do an efficient implementation with a small number of iterations (consider the mathematical properties of powers)
void ex20() {
	
	double base;
	int exponent;

	cout << "Base=";
	cin >> base;

	cout << "Exponent=";
	cin >> exponent;

	cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

}

// Edit MACROs here, according to your Matrix Dimensions for (geeksforgeeks)
// mat1[R1][C1] and mat2[R2][C2]
#define R1 2 // number of rows in Matrix-1
#define C1 2 // number of columns in Matrix-1
#define R2 2 // number of rows in Matrix-2
#define C2 2 // number of columns in Matrix-2

void mulMat(int mat1[][C1], int mat2[][C2])
{
	int rslt[R1][C2];

	cout << "Multiplication of given two matrices is:\n";

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			cout << rslt[i][j] << "\t";
		}

		cout << endl;
	}
}

//Compute Matrix multiplication and display “Impossible” if the matrices cant be multiplied.
void ex21() {

	// R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these
	// values in MACROs)
	int mat1[R1][C1] = { { 1, 1 },
						 { 2, 2 } };

	int mat2[R2][C2] = { { 1, 1 },
						 { 2, 2 } };

	if (C1 != R2) {
		cout << "The number of columns in Matrix-1  must "
			"be equal to the number of rows in "
			"Matrix-2"
			<< endl;
		cout << "Please update MACROs according to your "
			"array dimension in #define section"
			<< endl;

		exit(EXIT_FAILURE);
	}

	// Function call
	mulMat(mat1, mat2);

}

int main() {

	ex21();
	return 0;
}



//clasa de baza abstracta care sa aiba o fct virtuala pura

//caut formatting numbers 23