	
		/* wait_time.cpp: This program defines a class whose
	objects are generated random samples from an exponential 
	distribution (e.g. interarrival times) with density function:

		f_lambda(t) = (lambda)*exp(-lambda * t)

	where lambda > 0.0 and is, actually, the reciprocal of the
	mean. Its CDF (cumulative distribution function), found by 
	integration, is

		s = F(t) =  1.0 - exp(-lambda * t)

	so the inverse of the CDF is

		G(s) = t = -(1.0/lambda) * log(1.0 - s) 

	(note that log() is the natural logarithm). It is a standard
	theorem in probability that 

		X = G((double)rand()/(double)RAND_MAX);

	will constitute a (quasi) random sample from the exponential
	distribution f_lambda(t).

	The constructor function allocates memory from the heap for the 
	data array at the time of instantiation. The destructor
	function deallocates this memory (when the object created
	goes out of scope).  */

#include <iostream>		// for C++ I/O
using namespace std;

#include <stdio.h>		// for C I/O
#include <stdlib.h>
#include <string.h>		// for strcpy()
#include <time.h>		// for time() and ctime()
#include <unistd.h>		// for isatty()
#include <math.h>		// for log()

// - wait_time.h ------------------------------------------------------
//
// this entire block could be put in a separate header file: employee.h
// and included in the main program via:
//
// #include "wait_time.h"
//
#if !defined(WAIT_TIME_H)
#define WAIT_TIME_H	1
//

class	wait_time {		// define a waiting time class with
				// probability density f_lambda(t)
public:
				// the constructor function has some
				// default values for initialization 
	wait_time(int size, double lambd = 1.0);

				// the destructor function
	~wait_time(void);
				// public member functions 
	void	print(void);
	double	cdf_inverse(double s);
	double	average(void);
	void	insertion_sort(void);

private:
				// any information we don't want to
				// be visible except through member
				// function calls:
	double	*data;		//   pointer to data array (on heap)
	int	ssize;		//   sample size > 0
	double	lambda;		//   parameter lambda > 0.0

};
//
#endif
// - end of wait_time.h -----------------------------------------------

/* ------------------------------------------------------------------- */

#define	LAMBDA	2.0
#define SAMPLE_SIZE 96
				// function prototypes

/* ------------------------------------------------------------------- */

int main(int argc, char *argv[], char *envp[])
	{

	ios::sync_with_stdio();	// needed if we use BOTH printf()
				// and cout together
	srand(time(0));		// randomize the seed by calling
				// time() with a NULL pointer

		{		// instantiate a local random sample 
				// from the exponential distribution
		class wait_time first(SAMPLE_SIZE, LAMBDA);

				// print out the values
		printf("\nsample of size %d with lambda=%8.4f: \n",
			SAMPLE_SIZE, LAMBDA);
		first.print();
				// find the average
		printf("\nthe average is %8.4f", first.average());

		first.insertion_sort();	// sort the data values
		printf("\n");

				// run the same functions on the
				// sorted data:
				// print out the values
		printf("\nsorted sample of size %d with lambda=%8.4f: \n",
			SAMPLE_SIZE, LAMBDA);
		first.print();
				// find the average
		printf("\nthe average is %8.4f", first.average());

		} // end of local scope (destructor will be called)

	cout << "\n" << endl;
	return(0);	
	}  // end of main

/* ------------------------------------------------------------------- */

// ------------------------------------------------------------------- 
// class wait_time public functions start here
//
// this block could be put in a separate code file, the usual
// includes added, and it could then be compiled separately
// from the main() program above.
//
// -------------------------------------------------------------------

wait_time::wait_time(int size, double lambd)
		/* Constructor: this function is called whenever
	an object of class wait_time is instantiated. It allocates
	memory for the data array from the heap, which it fills using 
	rand() and cdf_inverse(). Note that the parameter values
	are checked for validity. */
	{
	int	i;
	double	x;

	lambda = lambd;			// set parameter
	if (lambda <= 0.0)
		{
		fprintf(stderr,
			"\nfatal error: lambda=%f \n\n", lambda);
		exit(-1);
		} 
	ssize = size;			// set sample size
	if (ssize < 1)
		{
		fprintf(stderr,
			"\nfatal error: ssize=%d \n\n", ssize);
		exit(-2);
		}
	data = new double[ssize];	// allocate memory
	if (data == (double *)NULL)
		{
		fprintf(stderr,
			"\nfatal error: memory allocation failed \n\n");
		exit(-3);
		}
					// generate random sample
	for (i = 0 ; i < ssize ; i++)
		{
		x = (double)rand()/(double)RAND_MAX;
		data[i] = cdf_inverse(x);
		}
	fprintf(stderr, "\n\n *** creating sample %p *** \n", this);
	return;
	}  // end of wait_time::wait_time

// -------------------------------------------------------------------

wait_time::~wait_time(void)
		/* Destructor: removes random sample and deallocates 
	memory from the heap */
	{
	fprintf(stderr, "\n\n *** destroying sample %p *** \n", this);

	delete [] data;			// use C++ delete operator
	return;
	}  // end of wait_time::~wait_time

// -------------------------------------------------------------------

double	wait_time::cdf_inverse(double s)
		/* This member function is the inverse of the CDF 
	(cumulative distribution function) */
	{
	return( -(1.0/lambda) * log(1.0 - s));
	} // end of wait_time::cdf_inverse

// -------------------------------------------------------------------

double	wait_time::average(void)
		/* This member function computes the average of
	the sample */
	{
	int	i;
	double	sum;

	sum = 0.0;
	for (i = 0 ; i < ssize ; i++)
		{
		sum = sum + data[i];
		}
	return(sum/(double)ssize);
	} // end of wait_time::average

// -------------------------------------------------------------------

void	wait_time::print(void)
		/* This member function is designed to print
	out all the samples from data[], lining up the columns */
	{
	int	i;

	for (i = 0 ; i < ssize ; i++)
		{
		if ((i % 8) == 0) 
			printf("\n");	// newline

		printf("%8.4f ", data[i]);
		}		
	printf("\n");
	return;
	}  // end of wait_time::print

// -------------------------------------------------------------------

void 	wait_time::insertion_sort(void)
		/* this function takes the data array and sorts it */
	{
	int	i, j, k;
	double	temp;

	for (i = 1 ; i < ssize ; i++)
		{
				/* so far

		data[0] < data[1] < .. data[i-1] have been sorted */

		for (j = 0 ; j < i ; j++)
			{
			if (data[i] < data[j])

			/* insert data[i] at the j-th position
				           |
	data[0] data[1].. data[j-1]   data[j]-> data[j+1]-> .. data[i-1]-> 

			   and move the rest up */
				{
				temp = data[i];
				for (k = i ; k > j ; k--)
					data[k] = data[k-1];
				data[j] = temp;
				break;
				}
			}  // end of for (j = ..
		}  // end of for (i =  ...
	return;
	}  // end of wait_time::insertion_sort

