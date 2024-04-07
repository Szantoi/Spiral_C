#ifndef BL_H
#define BL_H

#include "data.h"

bool isItEven(int num);

Point getCenterpoint(Spiral sp);

void rotationFirstStep(SpiralMatrix *SM);
void rotationStepping(SpiralMatrix *SM);

void SetColUp(SpiralMatrix *SM, int stepp);
void setColDown(SpiralMatrix *SM, int stepp);
void setColLeft(SpiralMatrix *SM, int stepp);
void setColRight(SpiralMatrix *SM, int stepp);

void mirrorMidRow(int **matrix, int row, int col);
void mirrorMidCol(int **matrix, int row, int col);

void rotationUPCW(SpiralMatrix *SM, int stepp);
void rotationLeftCW(SpiralMatrix *SM, int stepp);
void matrixSetting(SpiralMatrix *SM);

#endif