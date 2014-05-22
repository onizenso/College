		/* summation.c: sample C program to compute
		   the sum of a certain number of numbers. Enter
		   the numbers one at a time ending with "end"
		   Note that you can put the numbers in a datafile,
		   e.g. named "summation.txt" with each number on
		   a line, with the last line being "end", something
		   like:
				0.000000000000009
				0.00000000000009
				0.0000000000009
				0.000000000009
				0.00000000009
				0.0000000009
				0.000000009
				0.00000009
				0.0000009
				0.000009
				0.00009
				0.0009
				0.009
				0.09
				0.9
				9.0
				0.0000000000000005
				0.0000000000000005
				end

		   then you can run the program with redirection of
		   input:

			summation < summation.txt

		   Compile and link the program via:
		  
		   	gcc -g -lm summation.c -o summation 	

		   Why does it sometimes matter in which order you
		   add floating point number? 			*/

#include <stdio.h>		// needed for K&R C++ I/O
#include <stdlib.h>		// needed for ANSI C++ I/O
#include <math.h>		// needed for atan() function
#include <unistd.h>		// for isatty()

int	main()			// mandatory main function
	{
	double	sum = 0.0;	// keep the running sum here
	double	next;
	int	ret;

	if (isatty(0))
		printf("\nenter the next number or \"end\": ");
	ret = scanf("%lf", &next);	// note "%lf" and '&'
	while (ret == 1)
		{
		sum = sum + next;
		if (isatty(0))
			printf("enter the next number or \"end\": ");
		ret = scanf("%lf", &next);
		}
	printf("\nthe sum of your numbers is %.16f", sum);

	printf("\n\n");
	return(0);		// return zero for success
	}
	

