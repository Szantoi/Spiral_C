#include "bl.h"

bool isItEven(int num){
    if (num%2 == 0){
        return true;
    }
    return false;
}

Point getCenterpoint(Spiral spiralAct)
{
    Point Centerpoint;
    int row, col;

    row = (int)((spiralAct.size)/2);
    col = row;
    if(isItEven(spiralAct.size)){
        if(0 == strcmp(spiralAct.direction, SM_D_UP) || 0 == strcmp(spiralAct.direction, SM_D_DOWN)){
            col--;
        }
    }
    pointSet(&Centerpoint,row,col);
    return Centerpoint;
}

void rotationFirstStep(SpiralMatrix *SM)
{
    SMCPValue(SM, SM->number);
    pointSet(&SM->point, SM->centerPoint.row, SM->centerPoint.col);
}

void rotationStepping(SpiralMatrix *SM)
{
    if(0 == strcmp(SM->spiral.direction, SM_D_UP) || 0 == strcmp(SM->spiral.direction, SM_D_DOWN)){
        SM->point.row--;
    }else if (0 == strcmp(SM->spiral.direction, SM_D_LEFT) || 0 == strcmp(SM->spiral.direction, SM_D_RIGHT)){
        SM->point.col--;
    }
}

void SetColUp(SpiralMatrix *SM, int stepp)
{
    for (int i = 0; i < stepp; ++i)
    {
        SM->number += 1;
        SM->matrix[SM->point.row - i][SM->point.col] = SM->number;
    }
    SM->point.row -= stepp - 1;
}

void setColDown(SpiralMatrix *SM, int stepp)
{
    for (int i = 0; i < stepp; ++i)
    {
        SM->number += 1;
        SM->matrix[SM->point.row + i][SM->point.col] = SM->number;
    }
    SM->point.row += stepp - 1;
}

void setColLeft(SpiralMatrix *SM, int stepp)
{
    for (int i = 0; i < stepp; ++i)
    {
        SM->number += 1;
        SM->matrix[SM->point.row][SM->point.col - i] = SM->number;
    }
    SM->point.col -= stepp - 1;
}

void setColRight(SpiralMatrix *SM, int stepp)
{
    for (int i = 0; i < stepp; ++i)
    {
        SM->number += 1;
        SM->matrix[SM->point.row ][SM->point.col + i] = SM->number;
    }
    SM->point.col += stepp - 1;
}

void mirrorMidRow(int **matrix, int row, int col)
{
    for (int i = 0; i < row / 2; i++) {
        for (int j = 0; j < col; j++) {
            int temp = matrix[i][ j];
            matrix[i][ j] = matrix[row - i - 1][ j];
            matrix[row - i - 1][ j] = temp;
        }
    }
}

void mirrorMidCol(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][col - j - 1];
            matrix[i][col - j - 1] = temp;
        }
    }
}

void rotationUPCW(SpiralMatrix *SM, int stepp)
{
    rotationStepping(SM);
    setColRight(SM,stepp);
    SM->point.row++;
    setColDown(SM,stepp);
    SM->point.col--;
    setColLeft(SM,stepp);
    SM->point.row--;
    SetColUp(SM,stepp);
}

void rotationLeftCW(SpiralMatrix *SM, int stepp)
{
    rotationStepping(SM);
    SetColUp(SM,stepp);
    SM->point.col++;
    setColRight(SM,stepp);
    SM->point.row++;
    setColDown(SM,stepp);
    SM->point.col--;
    setColLeft(SM,stepp);
    
}

void matrixSetting(SpiralMatrix *SM)
{
    int stepp = 0;
    bool even = isItEven(SM->spiral.size);

    pointCopy(&SM->centerPoint ,getCenterpoint(SM->spiral));
    rotationFirstStep(SM);
    if(0 == strcmp(SM->spiral.direction,SM_D_UP) || 0 == strcmp(SM->spiral.direction,SM_D_DOWN)){
        for (stepp = 2; stepp < SM->spiral.size; stepp += 2){
            rotationUPCW(SM,stepp);
        }
        if(isItEven(SM->spiral.size)){
            rotationStepping(SM);
            setColRight(SM,stepp);
            SM->point.row++;
            setColDown(SM,stepp-1);
        }

        if(0 == strcmp(SM->spiral.direction,SM_D_UP) && 0 == strcmp(SM->spiral.rotation,SM_R_CW)){
        }
        else if (0 == strcmp(SM->spiral.direction,SM_D_UP) && 0 == strcmp(SM->spiral.rotation,SM_R_CCW)){
            mirrorMidCol(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
        else if(0 == strcmp(SM->spiral.direction,SM_D_DOWN) && 0 == strcmp(SM->spiral.rotation,SM_R_CW)){
            mirrorMidCol(SM->matrix, SM->spiral.size, SM->spiral.size);
            mirrorMidRow(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
        else if(0 == strcmp(SM->spiral.direction,SM_D_DOWN) && 0 == strcmp(SM->spiral.rotation,SM_R_CCW)){
            mirrorMidRow(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
    }else if (0 == strcmp(SM->spiral.direction,SM_D_LEFT) || 0 == strcmp(SM->spiral.direction,SM_D_RIGHT)){
        
        for (stepp = 2; stepp < SM->spiral.size; stepp += 2){
            rotationLeftCW(SM,stepp);
        }
        if(isItEven(SM->spiral.size)){
            rotationStepping(SM);
            SetColUp(SM,stepp);
            SM->point.col++;
            setColRight(SM,stepp-1);
        }

        if(0 == strcmp(SM->spiral.direction,SM_D_LEFT) && 0 == strcmp(SM->spiral.rotation,SM_R_CW)){
        }
        else if (0 == strcmp(SM->spiral.direction,SM_D_LEFT) && 0 == strcmp(SM->spiral.rotation,SM_R_CCW)){
            mirrorMidRow(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
        else if(0 == strcmp(SM->spiral.direction,SM_D_RIGHT) && 0 == strcmp(SM->spiral.rotation,SM_R_CW)){
            mirrorMidCol(SM->matrix, SM->spiral.size, SM->spiral.size);
            mirrorMidRow(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
        else if(0 == strcmp(SM->spiral.direction,SM_D_RIGHT) && 0 == strcmp(SM->spiral.rotation,SM_R_CCW)){
            mirrorMidCol(SM->matrix, SM->spiral.size, SM->spiral.size);
        }
    }

}
