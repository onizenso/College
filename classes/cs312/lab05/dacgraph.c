
		  /* dacgraph.c: this program prompts the user to enter 
		     the name of a directed graph datafile (see the
		     samples "dacgraph.dat" and "dacgraph2.dat") and 
		     does some analyses of the graph (print dependency
		     matrix, do depth-first traversal, ...). During
		     depth-first traversal it also watches for cycles
		     since there should be NONE. If it finds one it
		     prints an error message and exits.

		     right now the depth-first traversal chooses the
		     next child on the basis of LOWEST INDEX but this
	  	     has some disadvantages in that higher numbered
		     courses might be popped off the stack later -- and
		     taken earlier, which is not optimal.

		     the data file should look something like:

		 12
		  0    cs221
		  1    cs222
		  2    cs223
		  3    cs224
		  4    cs295
		  5    cs312
		  6    cs320
		  7    cs321
		  8    cs335
		  9    cs342
		 10    cs350
		 11    cs356
		a_comment:_from__to_____metric__capacity
		               0    1       1        1
		               1    2       1        1
		               0    3       1        1
		               1    4       1        1
		               2    5       1        1
		               4    5       1        1
		               0    6       1        1
		               2    7       1        1
		               2    8       1        1
		               4    9       1        1
		               2   10       1        1
		               2   11       1        1

		     where metric and capacity are set to 1 for active
		     uni-directional links. A future modification of the
		     program MIGHT use these values.  you can enter the 
		     directed graph datafile name on the command line:

			dacgraph dacgraph.dat

		     or you can wait to be prompted for it.
								Marc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODES 32
#define INFTY 32000			/* bigger than any node parameter */
#define UNSCANNED -32
#define MAX_DEPTH 128

char	infile[128];			/* input data file */
FILE	*fp;

	/* global graph information */

struct	nodeinfo {
	char	name[32];
	int	type;                   /* unused right now        */
	int	bufs;                   /* unused right now        */
	int	visited;		/* 0 or 1 */
	int	active_onstack;		/* 0 or 1 */
	}  nodes[ MAXNODES ];
int	numnodes;                       /* number of nodes read in */
int	metric[ MAXNODES ][ MAXNODES ];           /* matric matrix */
int	capacity[ MAXNODES ][ MAXNODES ];       /* capacity matrix */
int	kmat[ MAXNODES ][ MAXNODES ];
		
	/* stack global variables */
int	stack[ MAX_DEPTH ];
int	next_position = 0;
int	stack_pops[ MAX_DEPTH ];
int	next_pop = 0;
int	max_depth = MAX_DEPTH;

	/* variables global to max_flow(), walk(), layer_net()
	   find_ref(), and push_pull()  */

int	fdest,fsrc,fdisp,fminpot,frefnode;
int	flayer[ MAXNODES ];
int	fcap[ MAXNODES ][ MAXNODES ],flow[ MAXNODES ][ MAXNODES ];

				/* static variables needed by main() */
int	spath[ MAXNODES ];
int	pathlen;
int	startnodes[ MAXNODES ];
int	num_startnodes = 0;

			/* Function Prototypes */
void depth_first_traversal(int start_at_unvisited);
void init_stack(int stop_depth);
void push_stack(int nodenum);
int pop_stack(void);
int print_mat(int mat[][ MAXNODES ]);

/* --------------------------------------------------------------- */

int main(int argc, char *argv[], char *envp[])
	{
	int	i, j, k, l, ret;
	char	khar, chrline[132];

				/* initialize data structures and screen */
	numnodes = 0;
					/* check the command line */
	if (argc == 2)
		{
		strcpy(infile, argv[1]);
		}
	else
		{
					/* not on command line, get graph 
					   input file name from user */
		printf("enter name of graph input file: ");
		ret = scanf("%s", infile);
		if (ret != 1)
			{
			printf("no file entered. \n");
			return(-1);
			}
		}  /* end of else */

	fp = fopen(infile,"r");  	/* open file for reading */
	if (fp == NULL)
		{
		fflush(stdout);
		fprintf(stderr, 
			"  fopen error: no such file \"%s\" exists. \n\n",
			infile);
		return(-1);
		}

/* read in network graph data from input file */

	ret = fscanf(fp,"%d",&numnodes);	/* get number of nodes */
	if (ret != 1)
		{
		fflush(stdout);
		fprintf(stderr, 
			"\n  fscanf error: invalid number of nodes \n\n");
		return(-1);
		}
						/* we can now initialize 
				nodes and matrices since numnodes is known */
	for (i = 0 ; i < numnodes ; i++)
		{
		for (j = 0 ; j < 31 ; j++)
		  nodes[i].name[j] = ' ';
		nodes[i].name[31] = '\0';
		nodes[i].type = 0;
		nodes[i].bufs = 0;
		nodes[i].visited = 0;
		nodes[i].active_onstack = 0;
		}
	for (i = 0 ; i < numnodes ; i++)
		for (j = 0 ; j < numnodes ; j++)
		  {
		  if (i == j) metric[i][j] = 0;
		    else metric[i][j] = INFTY;
		  capacity[i][j] = 0;
		  kmat[i][j] = 0;
		  }
						/* read in node names */
	for (i = 0 ; i < numnodes ; i++)
		{
		ret = fscanf(fp,"%d %s",&j,chrline);
		if (ret != 2)
			{
			fflush(stdout);
			fprintf(stderr, 
			  "\n  fscanf error: invalid number of nodes \n\n");
			return(-1);
			}
		if ((j >= 0) && (j < numnodes))
			strcpy(nodes[j].name,chrline);
		}

						/* remove comment line */
	fscanf(fp,"%s",chrline);

						/* read in adjacencies and 
						   weights */
	while ((ret = fscanf(fp,"%d %d %d %d",&i,&j,&k,&l)) == 4)
		 /* from   to   metric(cost,dist,etc.) capacity */
		{
		metric[i][j] = k;
/*		metric[j][i] = k;  	these graphs are directed */
		if (l > 0)
		  {
		  kmat[i][j] = 1;
/*		  kmat[j][i] = 1;  	these graphs are directed */
		  }
		capacity[i][j] = l;
/*		capacity[j][i] = l;  	these graphs are directed */
		}
						/* find all startnodes */
	for (i = 0 ; i < numnodes ; i++)
		{
		for (j = 0 ; j < numnodes ; j++)
			{
			if ( (metric[j][i] != INFTY) &&
			     (metric[j][i] != 0) ) break;
			}
		if (j == numnodes)
			{
			startnodes[num_startnodes] = i;
			num_startnodes++;
			} 
		}  /* end of for (i = 0.. */

rloop:	printf("\nenter  <m> to show metric matrix, ");
	printf("\n       <t> to do depth-first traversal, ");
	printf("\n    or <q> to quit: ");
rlp1:	
	scanf("%s", chrline);

	if (chrline[0] == '\0') goto rlp1;
	printf("\n");

					/* check for un-allowable letters */
	if ((chrline[0] == 'm') || (chrline[0] == 't') ||
	    (chrline[0] == 'q') )
		khar = chrline[0];
	else
		goto rloop;

	switch(khar) {

	case 'm':   /* show metric matrix */
	  printf("metric matrix: \n");
	  print_mat(metric);
	  printf("\n");
	  goto rloop;

	case 't':   /* do depth-first traversal */
	  init_stack(numnodes);
	  for (i = 0 ; i < numnodes ; i++)
		{
		nodes[i].visited = 0;	/* mark all nodes not yet visited */
		nodes[i].active_onstack = 0;	/* nobody is active on the
					   stack right now */
		}
					/* do depth-first traversal 
					   beginning at startnodes */
	  if (num_startnodes == 0)
		{
		printf("error: graph has cycles - there are NO startnodes");
	  	printf("\n\n");
		goto rloop;
		}
	  else
		{
	  	for (i = 0 ; i < num_startnodes ; i++)
			depth_first_traversal(startnodes[i]);
		}
					/* print out node pops in
					   reverse order */
	  printf(" ");
	  for (i = (next_pop - 1) ; i >= 0 ; i--)
		{
		printf("-%5s", nodes[stack_pops[i]].name);
		}
	  printf("\n\n");
	  goto rloop;

	case 'c':   /* show capacity matrix */
	  printf("capacity matrix: \n");
	  print_mat(capacity);
	  printf("\n");
	  goto rloop;

	case 'q':      /* close files and quit program */
	  goto finish;

	}  /* end of switch */

finish: 
	fclose(fp); /* close input graph file */
	return(0);
	}  /* end of main */

/* ----------------------------------------------------------------
Stack and Depth-First Traversal Routines:
   ---------------------------------------------------------------- */

void depth_first_traversal(int start_at_unvisited)
		/* this function starts/continues a depth-first
	traversal at the indicated node (which SHOULD be unvisited).
	it also checks to see if a child node is already active on
	the stack, in which case this is a fatal error because it
	indicates that the graph is NOT acyclic. */
	{
	int	j, ret;

	if (nodes[start_at_unvisited].visited != 0)
		{
		fflush(stdout);
		fprintf(stderr, 
	"\n  depth_first_traversal error: node=%d has been visited \n\n",
			start_at_unvisited);
		exit(-1);
		}
					/* ok: push node onto stack */
	push_stack(start_at_unvisited);
	nodes[start_at_unvisited].visited = 1;
					/* look for UNvisited children 
					   LOWEST index first (this is
				   	   NOT optimal because it means
					   that some higher numbered courses 
					   will be popped off the stack 
					   later -- and taken earlier) */
	for (j = 0 ; j < numnodes ; j++) 
		{
		if ( (metric[start_at_unvisited][j] != INFTY) &&
		     (metric[start_at_unvisited][j] != 0)  )
			{
					/* make SURE that there is NO
					   cycle in the graph */
			if (nodes[j].active_onstack == 1)
				{
				fflush(stdout);
				fprintf(stderr,
"\n depth_first_traversal fatal error: edge from node %s to %s forms cycle",
		nodes[start_at_unvisited].name, nodes[j].name);
				fprintf(stderr, "\n as follows: ");
					/* trace cycle */
				fprintf(stderr, "%5s", nodes[j].name);
				while( (ret=pop_stack()) != j)
					{
					fprintf(stderr,
					"<-%5s", nodes[ret].name);
					}
				fprintf(stderr, "<-%5s\n\n", nodes[ret].name);
				exit(-1);
				}
					/* not a cycle, check whether node
					   has been visited previously */
			else if (nodes[j].visited == 0) 
				{
				depth_first_traversal(j); /* visit child */
				}
			}
		}  /* end of for (j = 0 ; .. */

	ret = pop_stack();		/* children sub-tree done:
					   remove fromstack */
	if (ret != start_at_unvisited)
		{
		fflush(stdout);
		fprintf(stderr, 
	"\n  depth_first_traversal error: pushed node=%d popped node=%d \n\n",
			start_at_unvisited, ret);
		exit(-1);
		}
	return;
	}  /* end of depth_first_traversal */

/* ---------------------------------------------------------------- */
void init_stack(int stop_depth)
		/* this function initializes the stack and sets
	a stop depth <= MAX_DEPTH */
	{
	if (stop_depth > MAX_DEPTH)
		{
		fflush(stdout);
		fprintf(stderr, 
		  "\n  stop_depth error: stop_depth=%d > MAX_DEPTH=%d \n\n",
			stop_depth, MAX_DEPTH);
		exit(-1);
		}
#if defined(DEBUG2)
	fflush(stdout);
	fprintf(stderr, "\n  init_stack: stop_depth=%d done.", stop_depth);
#endif
	next_position = 0;
	next_pop = 0;
	max_depth = stop_depth;
	return;
	}  /* end of init_stack */

/* ---------------------------------------------------------------- */

void push_stack(int nodenum)
		/* this function checks to see that there is room
	on the stack and if there is, pushes the node (by number)
	onto the stack. it also sets the node pushed as "active on the 
	stack" */
	{
	if (next_position > (max_depth - 1))
		{
		fflush(stdout);
		fprintf(stderr, 
  "\n  push_stack full stack error: stop_depth=%d  next_position=%d \n\n",
			max_depth, next_position);
		exit(-1);
		}
#if defined(DEBUG2)
	fflush(stdout);
	fprintf(stderr, "\n  push_stack: %s ", nodes[nodenum].name);
#endif
						/* ok */
	stack[next_position] = nodenum;
	next_position++;
	nodes[nodenum].active_onstack = 1;	/* active */
	return;
	}  /* end of push_stack */

/* ---------------------------------------------------------------- */

int pop_stack(void)
		/* this function pops a node (by number) off the
	stack unless there is nothing on the stack. it also 
	sets the node popped as "in-active on the stack" */
	{
	int	ret;
					/* check to make sure that
					   stack is not empty */
	if (next_position == 0)	
		{
		fflush(stdout);
		fprintf(stderr, 
  "\n  pop_stack empty stack error: next_position=%d  \n\n", next_position);
		exit(-1);
		}
	next_position--;
	ret = stack[next_position];
	nodes[ret].active_onstack = 0;	/* de-activate */

#if defined(DEBUG2)
	fflush(stdout);
	fprintf(stderr, "\n  pop_stack: ret=%s ", nodes[ret].name);
#endif
					/* check to make sure that
					   stack_pop[] array is not full */	
	if (next_pop > (MAX_DEPTH - 1))
		{
		fflush(stdout);
		fprintf(stderr, 
  "\n  pop_stack empty stack_pops[] full error: next_pop=%d  \n\n", 
			next_pop);
		exit(-1);
		}
	stack_pops[next_pop] = ret;
	next_pop++;

#if defined(DEBUG2)
	fflush(stdout);
	fprintf(stderr, "\n  next_pop=%d ", next_pop);
#endif
	return(ret);
	}  /* end of pop_stack */

/* ----------------------------------------------------------------
Graph Algorithm Routines:
   ---------------------------------------------------------------- */

int print_mat(int mat[][ MAXNODES ])
             /* prints metric or capacity matrix on the screen */
	{
	int	i,j;

	printf("\n");
	if (num_startnodes == 1)
		printf("%d startnode:  ", num_startnodes);
	else
		printf("%d startnodes: ", num_startnodes);
	for (i = 0 ; i < num_startnodes ; i++)
		{
		printf("%5s ", nodes[startnodes[i]].name);
		}
	printf("\nnumber of nodes is %d and matrix is: \n\n",numnodes);
	printf("      ");
	for (j = 0 ; j < numnodes ; j++) printf(" %5s",nodes[j].name);
	printf("\n");
	for (i = 0 ; i < numnodes ; i++)
		{
		printf("%5s ",nodes[i].name);
		for (j = 0 ; j < numnodes ; j++)
		  if (mat[i][j] == INFTY) printf("      ");
		    else printf(" %5d",mat[i][j]);
		printf("\n");
		}
	printf("\n");
	return(0);
	}  /* end of print_mat */

/* ----------------------------------------------------------- */

