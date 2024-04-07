#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define SM_D_UP "Up"
#define SM_D_DOWN "down"
#define SM_D_LEFT "left"
#define SM_D_RIGHT "right"

#define SM_R_CW "cw"
#define SM_R_CCW "ccw"

#define FILE_SUFFIX ".txt"
#define FILE_PREFIX "spiral"
#define FILE_NAME_CHAR_SISE 20
#define FILE_FIRST_LINE 25

typedef struct
{
    int size;
    char direction[10];
    char rotation[3];
}Spiral;

typedef struct
{
    int row;
    int col;
}Point;


void matrixPrint(int **matrix, int N, int M);

void spiralPrint(Spiral spiral);

void pointSet(Point *point,int row, int col);
void pointCopy(Point *point1, Point point2);

#endif