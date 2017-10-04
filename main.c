
#include <stdio.h> //just to check the result via console
#include "tpk172.h"

int main()
{
  char buf[27];
  int TRK_NO;
  int Command;
  int Price;
  int Volume;
  int Status;
  int Error;
  int Code;
  printf("Please type numbers in decimal\n");
  printf("TRK_NO: ");
  scanf("%d", &TRK_NO);
  printf("Command: ");
  scanf("%d", &Command);
  printf("Price: ");
  scanf("%d", &Price);
  printf("Volume: ");
  scanf("%d", &Volume);
  printf("Status: ");
  scanf("%d", &Status);
  printf("Error: ");
  scanf("%d", &Error);
  printf("Code: ");
  scanf("%d", &Code);

  formBuf(buf, TRK_NO, Command, Price, Volume, Status, Error, Code);

  printf("%s", buf);
}

