#include "data.h"


int** matrixSet(int rows, int cols)
{
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if( NULL == matrix){
        printf("Memory alloction failld!");
        exit(EXIT_FAILURE);
    }

    int num = 0, i, j;
    for (i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if( NULL == matrix[i]){
            printf("Memory alloction failld!");
            for (int k = 0; k < i; ++k) {
                free(matrix[k]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
        for ( j = 0; j < cols; ++j)
        {
            matrix[i][j] = num;
            num++;
        }
    }
    return matrix;
}

void matrixResize(int ***matrix, int newRows, int newCols) {
    *matrix = (int **)realloc(*matrix, newRows * sizeof(int*));
    if (NULL == *matrix) {
        printf("Memory allocation failed (newRows)!");
        exit(EXIT_FAILURE);
    }

    int num = 0, i, j;
    for (int i = 0; i < newRows; ++i) {
        int *newRow = (int *)realloc((*matrix)[i], newCols * sizeof(int));

        if (NULL == newRow) {
            printf("Memory allocation failed (newCols)!");
            for (int k = 0; k < i; ++k) {
                free((*matrix)[k]);
            }
            free(*matrix);
            exit(EXIT_FAILURE);
        }

        (*matrix)[i] = newRow;

        for (j = 0; j < newCols; ++j) {
            (*matrix)[i][j] = num;
            num++;
        }
    }
}
void resizeData(SpiralMatrix *SMdata, int size)
{
    if (SMdata->matrixSize <= size){
        SMdata->matrixSize = SMdata->spiral.size * 2;
        matrixResize(&SMdata->matrix, SMdata->matrixSize, SMdata->matrixSize);
    }
}

void spiralReSet(SpiralMatrix *SMdata, int size, char *direction, char *rotation)
{
    resizeData(SMdata, size);
    SMdata->spiral.size = size;
    strcpy(SMdata->spiral.direction, direction);
    strcpy(SMdata->spiral.rotation, rotation);
}

void saveSpiralMatrixToFile(SpiralMatrix *SMdata, const char *filename) {
    int size = SMdata->spiral.size;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }


    // Első sor: Beállítások
    fprintf(file, "%d %s %s\n", SMdata->spiral.size, SMdata->spiral.direction, SMdata->spiral.rotation);

    // Mátrix mentése
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", SMdata->matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void loadMatrixFromFile(SpiralMatrix *SMdata, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Hiba a fajl megnyitasakor.\n");
        exit(1);
    }

    fscanf(file, "%d", &SMdata->matrixSize);

    initData(SMdata, SMdata->matrixSize);

    fscanf(file, " %s %s", SMdata->spiral.direction, SMdata->spiral.rotation);
    for (int i = 0; i < SMdata->spiral.size; i++) {
        for (int j = 0; j < SMdata->spiral.size; j++) {
            fscanf(file, "%d", &SMdata->matrix[i][j]);
        }
    }
    spiralPrint(SMdata->spiral);
    matrixPrint(SMdata->matrix, SMdata->spiral.size, SMdata->spiral.size);

    fclose(file);
}


void initData(SpiralMatrix *SMdata, int size)
{
    SMdata->matrixSize = size * 2;
    SMdata->matrix = matrixSet(size, size);
    strcpy(SMdata->spiral.direction, SM_D_LEFT);
    strcpy(SMdata->spiral.rotation, SM_R_CW);
    SMdata->spiral.size = size;
    pointSet(&SMdata->point, 0, 0);
    pointSet(&SMdata->centerPoint, 0, 0);
    SMdata->number = 1;
}

void freeData(SpiralMatrix *SMdata) {
    for (int i = 0; i < SMdata->matrixSize; ++i) {
        free(SMdata->matrix[i]);
    }
    free(SMdata->matrix);
}

void SMCPValue(SpiralMatrix *SM, int number)
{
    SM->matrix[SM->centerPoint.row][SM->centerPoint.col] = number;
}