#include <stdio.h>
#include <time.h>

#include "ui.h"

int main()
 {
   welcome();
   description();

   srand((unsigned int)time(NULL));
   int size = 10;

   printf("What size NxN matrix do you want to start with?\n");
   
   while (1) {
      printf("Enter an integer [0-100]: ");
      if (scanf("%d", &size) != 1 || size < 0 || size > 100) {
         printf("Invalid input. Please try again.\n");
         while (getchar() != '\n');
         continue;
      }
      break;
   }
   int menu = 0, num = 1;
   SpiralMatrix SM;
   initData(&SM, size);

   while (1)
   {
      printMenu();
      while (1) {
         printf("Enter an integer [0-6]: ");
         if (scanf("%d", &menu) != 1 || menu < 0 || menu > 6) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
         }
         break;
      }
      switch (menu)
      {
         case 0:
            printf("---Goodbye!---");
            freeData(&SM);
            return 0;
         case 1:
            description();
            break;
         case 2:
            settingsSpiral(&SM);
            break;
         case 3:
            printSpiral(&SM);
            break;
         case 4:
            printMatrix(&SM, num);
            break;
         case 5:
            saveMatrix(&SM, num);
            break;
         case 6:
            loadMatrix(&SM);
            break;
         default:
            break;
      }
   }
 }