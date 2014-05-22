#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rndDbl() (double)rand()/(double)RAND_MAX
#define rndInt() (int)RAND_MAX/(int)rand()

typedef struct t_grid {
    int status;
    int over;
    float color[4];
    struct t_grid *prev;
    struct t_grid *next;
} Grid;

Grid** initGrid(Grid**, int);
void fillRand(Grid**);

Grid** grid;
int grid_dim;

int main(int argc, char* argv[]){
    if(argc<2){printf("Use: ./ms-txt <num>\n"); exit(EXIT_FAILURE);}

    grid_dim = atoi(argv[1]);

    //Initialize Grid
    grid = initGrid(grid, grid_dim);
    //Fill the grid with random assortment of 'V' and 'H'
    fillRand(grid);
    return 0;
}

Grid** initGrid(Grid** iGrid, int size)
{
    int g = 0; //Loop counter for memory allocation
    
    //Allocate memory for grid, test to ensure allocation succeeded
    if((iGrid = (struct Grid*)malloc(size)) == -1) 
    {printf("Memory error"); exit(EXIT_FAILURE);}
    
    for(;g<size;g++)
    {
        if((iGrid[g] = (struct Grid*)malloc(size)) == -1) 
        {printf("Memory error"); exit(EXIT_FAILURE);}
    }

    return iGrid;
}

void fillRand(Grid** tmpGrid)
{
    int i=0, j=0;
    for(i=0; i < grid_dim; i++)
        for(j=0; j < grid_dim; j++)
            tmpGrid[i][j].status = (rand()%2==0) ? 1 : 2;

    for(i=0; i < grid_dim; i++)
        for(j=0; j < grid_dim; j++)
            printf("Status row: %i col: %i = %i\n", i, j, tmpGrid[i][j].status);
}
