#ifndef TPK172_H
#define TPK172_H

void formBuf(char *a, int TRK_NO, int Command, int Price, int Volume, int Status, int Error, int Code);
//SOH = 1; STX = 2; ETX = 3; CRC is calculated inside the function

#endif // TPK172_H
