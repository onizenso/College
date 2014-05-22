	
		/* gcd_recurs.cpp: we use the Euclidean algorithm to
		find the greatest common divisor of two positive
		integers but, unlike our earlier program gcdivsor.cpp,
		we use a RECURSIVE function intead. Here is an
		example run with the numbers 465 and 2005:

		  entering find_gcd_recurs(465,2005).. swap(2005,465)
		  entering find_gcd_recurs(465,145).. 
		  entering find_gcd_recurs(145,30).. 
		  entering find_gcd_recurs(30,25).. 
		  entering find_gcd_recurs(25,5)..  */

#include <iostream>
using namespace std;

				// function prototypes
int	find_gcd_recurs(int m, int n);

/* ---------------------------------------------------------------- */

int main()
	{
	int	num1, num2, gcd;

	do {
		cout << "\nplease enter a positive integer: ";
		cin >> num1;
		} while (num1 <= 0);
	do {
		cout << "please enter another positive integer: ";
		cin >> num2;
		} while (num2 <= 0);

	gcd = find_gcd_recurs(num1, num2);
	cout << "\n\nthe gcd of " << num1 << " and " << num2
		<< " is " << gcd;

	cout << "\n\n";	
	return(0);
	}  // end of main

/* ---------------------------------------------------------------- */

int	find_gcd_recurs(int m, int n)
		/* this function takes two positive integers m, n
	(passed by value) and returns the greatest common divisor 
	of m and n (gcd) */
	{
	int	rem, swp, ret;

	cout << "\n  entering find_gcd_recurs(" << m << ","
		<< n << ").. ";

	if (m < n)		// swap m and n if n is larger
		{ 
		swp = m;	
		m = n;	
		n = swp;	
		swp = 1; 	// a swap was done
		}
	else
		{ 
		swp = 0; 	// no swap done
		}
	if (swp == 1) 
		cout << "swap(" << m << "," << n << ")";

	rem = m % n;		// get remainder of division of m by n
	if (rem == 0)
		ret = n;	// n was the gcd
	else
		ret = find_gcd_recurs(n, rem);	// call ourselves (but
				// with a smaller remainder)
	return(ret);
	}  // end of find_gcd_recurs

