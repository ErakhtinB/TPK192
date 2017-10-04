#ifndef TPK172_H
#define TPK172_H

long int formBuf(char *a, long int TRK_NO, long int Command, long int Price, long int Volume, long int Error, long int Code);
//SOH = 1; STX = 2; ETX = 3; CRC is calculated inside the function

#endif // TPK172_H
