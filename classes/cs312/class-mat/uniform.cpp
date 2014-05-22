			/* uniform distribution of n numbers
			generated on [a,b] using stderr and 
			redirection, with 0.0 as sentinel.
			Best way to run program is

			uniform 2> mydata.txt		 
	
			NOTE: if you DON'T want the sentinel
			edit mydata.txt and remove it from
			the last line. */

#include <iostream>
using namespace std;

#include <stdio.h>	// for printf()
#include <stdlib.h>	// for rand() and srand()
#include <time.h>	// for time()

int	main()
	{
	int	n, index;
	double	a, b, x;

	ios::sync_with_stdio();	// we want to use both printf() and cout

	srand(time(0));		// set the seed by the raw time

	cout << "\nPlease enter the two interval endpoints [a,b]: ";
	cin >> a;
	cin >> b;
	cout << "\nPlease enter total numbers to generate: ";
	cin >> n;

	for (index = 1 ; index <= n ; index++)	
		{
		x = a + (b - a)*((double)rand()/(double)RAND_MAX);

				// can redirect to file via:
				// uniform 2> mydata.txt
		fprintf(stderr, "%8.4f ", x);
		if ((index % 8) == 0)		
			fprintf(stderr, "\n");
		} // end of for
	fprintf(stderr, "\n0.0");	// add sentinel at end (0.0);

	cout << "\n\n";
	return(0);
	}	
		

	


