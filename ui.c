#include "ui.h"

void separatorLine()
{
    printf("-------------------\n");
}

void lineSpacing()
{
    printf("\n");
}

void pauseRun()
{
    printf("Press any key to continue...\n");
    while (getchar() != '\n');
    getchar();
}

void welcome()
{
    lineSpacing();
    separatorLine();
    printf("_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("Welcome to the program!\n");
    printf("This application draws you an arbitrary NxN matrix.\n");
    lineSpacing();
    pauseRun();
}

void description()
{
    separatorLine();
    printf("Description:");
    printf("\nHe draws successive numbers on the surface of the console, which grow from \n");
    printf("the inside of the matrix to the outside in a spiral form.\n");
    lineSpacing();
    printf("You have the option to specify the size of the matrix,\n");
    printf("start writing up, down, left, right after the number 1 and \n");
    printf("with which direction of rotation to do this.\n");
    lineSpacing();
    pauseRun();
}

void printMenu()
{
    separatorLine();
    printf("Please choose from the following options:\n");
    printf("1. Description\n");
    printf("2. Spiral setting\n");
    printf("3. Displaying Spiral's settings\n");
    printf("4. Print matrix\n");
    printf("5. Save matrix to file\n");
    printf("6. Loading matrix from file\n");
    printf("0. Exit\n");
}

void settingsSpiral(SpiralMatrix *SM)
{
    Spiral SpiTemp;
    SpiTemp.size = -1;
    strcpy(SpiTemp.direction, "");
    strcpy(SpiTemp.rotation, "");
    int menu = 0;

    separatorLine();
    printf("Enter the size of the spiral.\n");
    printf("It will also be the size of the matrix.\n");
    while (1) {
        printf("Enter an integer and greater than 2: ");
        if (scanf("%d", &SpiTemp.size) != 1 || SpiTemp.size <= 2) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    separatorLine();
    printf("Enter the direction of the spiral.\n");
    printf("1. up\n");
    printf("2. down\n");
    printf("3. left\n");
    printf("4. right\n");
    while (1) {
        printf("Enter an integer [1-4]: ");
        if (scanf("%d", &menu) != 1 || menu < 1 || menu > 4) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    switch (menu)
      {
        case 1:
            strcpy(SpiTemp.direction, SM_D_UP);
            break;
        case 2:
            strcpy(SpiTemp.direction, SM_D_DOWN);
            break;
        case 3:
            strcpy(SpiTemp.direction, SM_D_LEFT);
            break;
        case 4:
            strcpy(SpiTemp.direction, SM_D_RIGHT);
            break;
        default:
            break;
      }

    separatorLine();
    menu = 0;
    printf("Enter the rotation of the spiral.\n");
    printf("1. cw: clockwise\n");
    printf("2. ccw: counterclockwise\n");
    while (1) {
      printf("Enter an integer [1-2]: ");
      if (scanf("%d", &menu) != 1 || menu < 1 || menu > 2) {
          printf("Invalid input. Please try again.\n");
          while (getchar() != '\n');
          continue;
      }
      break;
    }
    switch (menu)
    {
        case 1:
            strcpy(SpiTemp.rotation, SM_R_CW);
            break;
        case 2:
            strcpy(SpiTemp.rotation, SM_R_CCW);
            break;
        default:
            break;
    }
    if (0 < SpiTemp.size && 0 != strcmp(SpiTemp.direction, "") && 0 != strcmp(SpiTemp.rotation, ""))
    {
        spiralReSet(SM, SpiTemp.size, SpiTemp.direction, SpiTemp.rotation);
        printf("The spiral has changed!\n");
        
    }else
    {
        printf("The spiral has not changed!\n");
    }
    spiralPrint(SM->spiral);
    pauseRun();
    lineSpacing();
}

void printSpiral(SpiralMatrix *SM)
{
    separatorLine();
    spiralPrint(SM->spiral);
    pauseRun();
}

void printMatrix(SpiralMatrix *SM, int num)
{
    separatorLine();
    SM->number = num;
    matrixSetting(SM);
    lineSpacing();
    matrixPrint(SM->matrix, SM->spiral.size, SM->spiral.size);
    lineSpacing();
    pauseRun();
    lineSpacing();
}

void saveMatrix(SpiralMatrix *SM, int num)
{
    separatorLine();
    SM->number = num;
    matrixSetting(SM);

    char filename[FILE_NAME_CHAR_SISE]; 
    sprintf(filename, "%s%d%s%s%s", FILE_PREFIX, SM->spiral.size, SM->spiral.direction, SM->spiral.rotation,  FILE_SUFFIX);

    for (int i = 0; filename[i]; i++) {
        filename[i] = tolower(filename[i]);
    }

    saveSpiralMatrixToFile(SM, filename);
    printf("The file is ready!\n");
    printf("filename: %s\n",filename);
    pauseRun();
    lineSpacing();
}

void loadMatrix(SpiralMatrix *SM)
{
    separatorLine();
    printf("Please enter the file name (without the extension)\n");
    printf("Example: 'spiral10upcw'\n");

    char filename[FILE_NAME_CHAR_SISE];
    scanf("%s",filename);

    sprintf(filename, "%s%s", filename,  FILE_SUFFIX);
    loadMatrixFromFile(SM,filename);
    
    pauseRun();
    lineSpacing();
}
