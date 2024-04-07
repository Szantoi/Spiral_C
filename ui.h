#ifndef UI_H
#define UI_H


#include "bl.h"

void separatorLine();
void lineSpacing();
void pauseRun();

void welcome();
void description();
void printMenu();

void settingsSpiral(SpiralMatrix *SM);
void printSpiral(SpiralMatrix *SM);

void printMatrix(SpiralMatrix *SM, int num);
void saveMatrix(SpiralMatrix *SM, int num);
void loadMatrix(SpiralMatrix *SM);

#endif