
		/* entropy_gen.c: this program accepts a desired
		entropy (as a percentage: (E/log2(n))*100.0) and
		a desired number of elements, and tries to build a
		sawtooth distribution (with some randomness) which
		has approximately the desired entropy (5-90%).
		It writes this data set to stderr (which you can
		capture by redirection).

		NOTE: it may NOT be possible to create small datasets
		with very small percentages of entropy and the program
		will exit with a warning in that case.

		if the list of length n consists of k contiguous 
		in-order segments:

			S_0, S_1, ... , S_k-1

		each of length:

			m_0, m_1, ... , m_k-1  (m_0 + m_1 + ... + m_k-1 = n)

		then let p_i = m_i/n for i = 0, 1, 2, ... , n-1 
		and define the entropy of the list to be:

			E = -( p_0*log2(p_0) + ... + p_k-1*log2(p_k-1) )

		so that IF the list is actually sorted, k = 1, m_0 = n
		and p_0 = 1 and

			E = -(1*log2(1)) = 0.

		the worst case occurs when the list is in reverse
		order so that k = n, m_i = 1
		and p_i = 1/n and

			E = -n*((1/n)*log2(1/n)) 
			
			  = n*((1/n)*log2(n))

			  = log2(n) 			

		recall that log2(x) = log(x)/log(2.0). the program is 
		invoked by typing

			entropy_gen 2>data_output.txt 	
	
		where "data_output.txt" is your desired name for the
		sawtooth dataset. 				*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <math.h>
#include <time.h>
#include <errno.h>	/* for perror() */

#define MIN_NUMS      5
#define MAX_NUMS 100000

			/* function prototypes */
double entropy(double x[], int n);	

/* ------------------------------------------------------------------- */

int main(int argc, char *argv[], char *envp[])
	{
	int	i, j, k, ret, sum, tmpint, from , to;
	double	entrop, actual_k, sawtooth;
	double	accum_sum, tmpdouble;
	double	actual_entropy;
	int	count;				/* number in array */
	double	array[MAX_NUMS]; 		/* array */
	int	length_m[MAX_NUMS];		/* array of sub-lengths
						adding up to count */
	
	srand(time(0));		// set the seed by the raw time

enter1: fprintf(stdout, "\nEnter desired number (%d-%d) of elements: ",
		MIN_NUMS, MAX_NUMS);
	ret = fscanf(stdin, "%d", &count);
	if ( (ret != 1) || (count < MIN_NUMS) || (count > MAX_NUMS) )
		{
		fflush(stdout);
		fprintf(stderr, "\n *** invalid value *** \n");
		goto enter1;
		}
enter2: fprintf(stdout, "\nEnter desired %%-age (5.00, 90.0) of entropy: ");
	ret = fscanf(stdin, "%lf", &entrop);
	if ( (ret != 1) || (entrop < 5.0) || (entrop > 90.0) )
		{
		fflush(stdout);
		fprintf(stderr, "\n *** invalid value *** \n");
		goto enter2;
		}
	entrop = entrop/100.0;		/* transform to (0.0, 1.0) */
					/* find closest integer
				k such that:

					log2 k       ln k
					---------- = --------- = entrop 
					log2 count   ln count
								       */
	actual_k = exp(log((double)count)*entrop);
	k = (int)(actual_k + 0.5);
	fprintf(stdout, 
    "\n desired entrop=%6.4f actual_k=%.2f k=%d and actual_entropy=%7.5f",
		entrop, actual_k, k, log(k)/log(count));	

					/* check if data set is TOO SMALL
				to produce a (small) entropy value */
	if (k <= 1)
		{
		fflush(stdout);
		fprintf(stderr, 
 "\n error: k=%d: dataset (%d) is too small for desired entropy (%7.4f%%)",
			k, count, entrop);
		fprintf(stderr,
 "\n              increase either the number of elements or the entropy \n");
		return(-1);
		}
					/* now creat the sub-lengths
				which will add up to count. we have to
				check repeatedly whether we are over
				so that no length is zero */
	sum = 0;
	accum_sum = 0.0;
	for (i = 0 ; i < k ; i++)
		{
		tmpdouble = ((double)count/(double) k);
		tmpint = (int)(((double)count/(double) k) + 0.5);
					/* check to see if round-off has
				carried us too little or too much */
		if ((accum_sum - (double)sum) > 1.0)
			tmpint++;
		else if (((double)sum - accum_sum) > 1.0)
			tmpint--;
		if ( (i != (k-1)) && ((sum + tmpint) < count) )
			length_m[i] = tmpint;
		else
			length_m[i] = count - sum;
		if (length_m[i] == 0)
			{
			fflush(stdout);
			fprintf(stderr, 
			  "\n fatal error: length_m[%d]=0 ... exiting", i);
			return(-1);
			}
		accum_sum = accum_sum + tmpdouble;
		sum = sum + length_m[i];
		}  /* end of for (i = .. */
	if (sum != count)
		{
		fflush(stdout);
		fprintf(stderr, 
		  "\n fatal error: sum=%d count=%d ... exiting", sum, count);
		return(-1);
		}

#if defined(DEBUG2)			 /* DEBUG2: display lengths */ 
	for (i = 0 ; i < k ; i++)
		{
		if ((i % 8) == 0) fprintf(stdout, "\n");
		fprintf(stdout,"%8d ", length_m[i]); 
		}  /* end of for (i = .. */
#endif
					/* compute (new) actual entropy */
	actual_entropy = 0.0;
	for (i = 0 ; i < k ; i++)
		{
		tmpdouble = (double)length_m[i]/(double)count;
		actual_entropy = actual_entropy -
			(tmpdouble * log(tmpdouble)/log(2.0));
		}
					/* normalize */
	actual_entropy = (actual_entropy/log((double)count))*log(2.0);
	fprintf(stdout, 
    "\n         entrop=%6.4f actual_k=%.2f k=%d and actual_entropy=%7.5f",
		entrop, actual_k, k, actual_entropy);

					/* at this point we have the
				desired sub-lengths. we now need to
				generate the desired values (in order)
				for each sub-range. */
	from = -1;
	to = -1;
	for (i = 0 ; i < k ; i++)
		{
		from = to + 1;
		to = to + length_m[i];
					/* generate values with some
				randomization with
				array[from] < array[from - 1]	

				and a general sawtooth growth 
				which will be greater for lower
				entropy values. */

					/* ad hoc test */
		for (j = 0 ; j < length_m[i] ; j++)
			{
			if (i == 0)
				sawtooth = 0.0;
			else
				sawtooth = array[from - 1] *
					(0.5 * (1.00 - actual_entropy));
			array[from + j] = (double)j + sawtooth +
				(0.4 - 0.8*((double)rand()/(double)RAND_MAX));
			}
		}
	if (to != (count - 1))
		{
		fflush(stdout);
		fprintf(stderr, 
		  "\n fatal error: to=%d count=%d ... exiting", to, count);
		return(-1);
		}


					/* *** TEST *** actual array */
	fflush(stdout);
	tmpdouble = entropy(array, count);
	tmpdouble = (tmpdouble/log(count))*log(2.0);
	fprintf(stdout, "\n\nTest Entropy=%7.5f ", tmpdouble);

					/* write values to stderr */
	fflush(stdout);
	for (i = 0 ; i < count ; i++)
		{
		fprintf(stderr, "\n%12.5f ", array[i]);
		}


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
		x[n-1] = 9.345 <- m[4] = 4  sum = 13  p[4] = 4/n  k = 5  

	the result will be a number in the interval [ 0.0 , log2(n) ] */
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

#if defined(DEBUG2)
		fprintf(stderr, 
 "\n i=%3d k=%3d sum=%3d m[%3d]=%3d p[%3d]=%10.5f ",
			i, k, sum, k, m[k], k, p[k]);
#endif

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


