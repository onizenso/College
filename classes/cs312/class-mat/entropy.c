
		/* entropy.c: this program measures the entropy
		of a partially ordered list as follows:

		if the list of length n consists of k contiguous 
		in-order segments:

			S_0, S_1, ... , S_k-1

		each of length:

			m_0, m_1, ... , m_k-1  (m_0 + m_1 + ... + m_k-1 = n)

		then let p_i = m_i/n for i = 0, 1, 2, ... , n-1 
		and define the entropy of the list to be:

			E = -( p_0*log2(p_0) + ... + p_k-1*log2(p_k-1) )

		so that IF the list is actually sorted, k = 1, n_0 = n
		and p_0 = 1 and

			E = -(1*log2(1)) = 0.

		the worst case occurs when the list is in reverse
		order so that k = n, n_i = 1
		and p_i = 1/n and

			E = -n*((1/n)*log2(1/n)) 
			
			  = n*((1/n)*log2(n))

			  = log2(n) 			

		recall that log2(x) = log(x)/log(2.0). the program is 
		invoked by typing

			entropy datafile.txt 		*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <math.h>
#include <errno.h>	/* for perror() */

#define MAX_NUMS 25000

			/* function prototypes */
double entropy(double x[], int n);	

/* ------------------------------------------------------------------- */

int main(int argc, char *argv[], char *envp[])
	{
	int	count, i, ret;
	double	value;
	double	orig[MAX_NUMS]; 		/* ORIGINAL array */
	FILE	*fp;

	if (argc == 2)
		{
		fp = fopen(argv[1], "r");	/* open file for read */
		}
	else
		{
		printf(
	"\n follow instructions! invoke this program as follows: ");
		printf("\n entropy [name of data file] \n\n");
		return(-1);		/* failure */
		}
					/* see if open succeeded */
	if (fp == (void *)NULL)
		{
		fprintf(stderr, "\n  fopen(\"%s\", \"r\"); failed", argv[1]); 
		perror("\n  reason: ");
		return(-1);		/* failure */
		}
					/* read data from file */
	count = 0;
	while  (  (count < MAX_NUMS) &&
		  ((ret = fscanf(fp, "%lf", &orig[count])) == 1))
		{
		count++;
		}
	fclose(fp);			/* close data file */

					/* show data */
	fprintf(stdout, "\nRead %d data items from file %s: ", count, argv[1]);
	for (i = 0 ; i < count ; i++)
		{
		fprintf(stdout, "\n  %10.5f ", orig[i]);
		fflush(stdout);
		}
					/* find entropy */
	value = entropy(orig, count);
	fprintf(stdout, 
		"\nEntropy: %10.5f   Entropy/log2(n): %10.5f%%", 
			value, (100.0*value*log(2.0))/log(count));

	fprintf(stdout, "\n\n");
	return(0);
	}  /* end of main */

/* ------------------------------------------------------------------- */

double entropy(double x[], int n)
		/* find the entropy of the partially ordered list,
	for example:

		x[i]      	  m[k]	    sum =  0  p[k]        k = 0
		x[0]   = 0.345            
		x[1]   = 0.888
		x[2]   = 1.234 <- m[0] = 3  sum =  3  p[0] = 3/n  k = 1
		x[3]   = 1.095
		x[4]   = 3.445 <- m[1] = 2  sum =  5  p[1] = 2/n  k = 2
		x[5]   = 2.220
		x[6]   = 6.789
		x[7]   = 6.880 <- m[2] = 3  sum =  8  p[2] = 3/n  k = 3
		x[8]   = 4.001 <- m[3] = 1  sum =  9  p[3] = 1/n  k = 4
		x[9]   = 1.001
		x[10]  = 3.709
		x[11]  = 5.550
		 ...
		x[n-1] = 9.345 <- m[4] = 4  sum = 13  p[4] = 4/n  k = 5  */
	{
	int	k, i, count, sum;
	double	last, value;
	int	*m;
	double	*p;
					/* allocate memory */
	m = (int *)malloc(n*sizeof(int));
	if (m == (int *)NULL)
		{
		fflush(stdout);
		fprintf(stderr, "\n  fatal error in malloc(%d*sizeof(int))",
			n);
		return(-1.0);
		}
	p = (double *)malloc(n*sizeof(double));
	if (p == (double *)NULL)
		{
		fflush(stdout);
		fprintf(stderr, "\n  fatal error in malloc(%d*sizeof(double))",
			n);
		return(-1.0);
		}
					/* start algorithm */
	i = 0;
	k = 0;
	sum = 0;
	do 	{
		i = sum;
		count = 1;
		last = x[i];
		while ( ((i + 1) < n) && (last <= x[i + 1]) )
			{
			i++;
			count++;
			last = x[i];	/* update last */
			}
		m[k] = count;
		sum = sum + count;
		p[k] = (double)count/(double)n;

/* *** DIAG *** */
		fprintf(stderr, 
 "\n i=%3d k=%3d sum=%3d m[%3d]=%3d p[%3d]=%10.5f ",
			i, k, sum, k, m[k], k, p[k]);

		i++;
		k++;
	   	} while (i < n);
					/* compute entropy */
	value = 0.0;
	for (i = 0 ; i < k ; i++)
		{
		value = value +  p[i]*(log(p[i])/log(2.0));
		}
				/* note: we don't want to return -0.00 */
	if (value == 0.0)
		return(0.0);
	else
		return(-value);
	}  /* end of entropy */


