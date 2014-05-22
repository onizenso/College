	
		/* factor_recurs.cpp: We factor a number with
		the recursive function first_prime() */


#include <iostream>
using namespace std;

				// function prototypes
int	first_prime(int m);

/* ---------------------------------------------------------------- */

int main()
	{
	int	num, ret;

	do {
		cout << "\nplease enter an integer > 1: ";
		cin >> num;
		} while (num <= 2);
	cout << "\n" << num << " factors as ";
	ret = first_prime(num);

	cout << "\n\n";	
	return(0);
	}  // end of main

/* ---------------------------------------------------------------- */

int	first_prime(int m)
		/* this recursive function takes a positive integer m 
	and finds its smallest prime factor p. If p = m it returns 0 to
	indicate that m is prime. otherwise it calls first_prime(m/p)
	until a zero is returned. */
	{
	int	p, ret;

	for (p = 2 ; p < m ; p++)
		if ( (m % p) == 0) break;

// DIAGNOSTIC
//	cout << "\nentering first_prime with m=" << m << endl; 

	if (p == m)
		{
		cout << p;			
		return(0);			// m is prime
		}
	do 	{
		cout << p << "*";
		ret = first_prime(m/p);		// m is composite
		} while (ret > 0);
	return(0);
	}  // end of first_prime

