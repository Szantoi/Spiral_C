#include "head.h"

void matrixPrint(int **matrix, int row, int col)
{
    int i, j;
    int numSize = col * row;
    if (10 > numSize)
    {
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                printf("%2i",matrix[i][j]);
            }
            printf("\n");
        }
    }else if (100 > numSize)
    {
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                printf("%3i",matrix[i][j]);
            }
            printf("\n");
        }
    }else if (1000 > numSize)
    {
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                printf("%4i",matrix[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("\n\n...\n The matrix size is too large to display! \n...\n\n");
    }
    
    
}

void spiralPrint(Spiral spiral)
{
    printf("Spiral: \n\tSize: \t%i \n\tDirection: \t%s \n\tRotation: \t%s\n", spiral.size, spiral.direction, spiral.rotation);
}

void pointSet(Point *point,int row, int col){
    point->row = row;
    point->col = col;
}

void pointCopy(Point *point1, Point point2)
{
    point1->row = point2.row;
    point1->col = point2.col;
}

