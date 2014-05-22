
		/* gcdivisor.cpp: we use the Eucliean algorithm to
		find the greatest common divisor of two positive
		integers. Example with 

			larger = 424
			smaller = 56

			 424 = 7 * 56  +  32
			  56 = 1 * 32  +  24
			  32 = 1 * 24  +   8
			  24 = 3 *  8  +   0   */

#include <iostream>
using namespace std;

int	main()
	{
	int	num1, num2, larger, smaller, quotient, remainder, temp;

					// get numbers
	cout << "\nEnter Larger ";
	cin >> larger;
	cout << "\nEnter Smaller ";
	cin >> smaller;
					// save for final output
	num1 = larger;
	num2 = smaller;
					// check consistency
	if (smaller > larger)
		{
		cout << "\nCan\'t you read instructions!";
		temp = larger;		// swap varibles
		larger = smaller;
		smaller = temp;
		}  // end of if
					// start algorithm
	do	{
					// compute
		quotient = larger/smaller;
		remainder = larger % smaller;
					// diagnostic
		cout << "\n " << larger << " = " << quotient << " * "
			<< smaller << "  +  " << remainder;	

					// update
		larger = smaller;
		smaller = remainder;
		} while (remainder > 0);

	cout << "\n\nthe greatest common divisor gcd("
		<< num1 << "," << num2 << ") is " << larger << endl;
	cout << "\n\n";
	return(0);
	} // end of main

