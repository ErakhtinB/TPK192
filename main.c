#define BUFF_SIZE 23

#include <stdio.h> //just to check the result via console
#include "tpk172.h"

int main()
{
  char buf[BUFF_SIZE];
  long int TRK_NO;
  long int Command;
  long int Price;
  long int Volume;
  long int Error;
  long int Code;
  printf("Please type numbers in decimal\n");
  printf("TRK_NO: ");
  scanf("%ld", &TRK_NO);
  printf("Command: ");
  scanf("%ld", &Command);
  printf("Price: ");
  scanf("%ld", &Price);
  printf("Volume: ");
  scanf("%ld", &Volume);
  printf("Error: ");
  scanf("%ld", &Error);
  printf("Code: ");
  scanf("%ld", &Code);

  switch(formBuf(buf, TRK_NO, Command, Price, Volume, Error, Code))
  {
        case 0:
        {
          for (long int i = 0; i < BUFF_SIZE - 1; i++)
          {
              printf("%c", buf[i]);
          }
          break;
        }
        case 1:
        {
          printf("Bad TRK_NO");
          break;
        }
        case 2:
        {
            printf("Bad Command");
            break;
        }
        case 3:
        {
            printf("Wrong Price");
            break;
        }
        case 4:
        {
            printf("Bad Volume");
            break;
        }
        case 5:
        {
            printf("Bad Error Value");
            break;
        }
        case 6:
        {
            printf("Bad Code");
            break;
        }
        default: break;
  }
  return 0;
}

