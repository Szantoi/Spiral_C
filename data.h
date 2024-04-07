#ifndef DATA_H
#define DATA_H

#include <stdlib.h>

#include "head.h"

typedef struct{
    int **matrix;
    int matrixSize;
    Spiral spiral;
    Point centerPoint;
    Point point;
    int number;
}SpiralMatrix;

void SMCPValue(SpiralMatrix *SM, int number);

int** matrixSet(int rows, int cols);
void matrixResize( int ***matrix, int newRows, int newCols);

void resizeData(SpiralMatrix *SMdata, int size);

void spiralReSet(SpiralMatrix *SMdata, int size, char *direction, char *rotation);

void saveSpiralMatrixToFile(SpiralMatrix *SMdata, const char *filename);
void loadMatrixFromFile(SpiralMatrix *SMdata, const char *filename);

void initData(SpiralMatrix *SMdata, int size);
void copyData(SpiralMatrix *SMdata1, SpiralMatrix *SMdata2);
void freeData(SpiralMatrix *SMdata);

#endif