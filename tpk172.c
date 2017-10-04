#include "tpk172.h"

long int formBuf(char *a, long int TRK_NO, long int Command, long int Price, long int Volume, long int Error, long int Code)
{
    //Checking incoming data
    if (TRK_NO > 0x7F || TRK_NO < 0) return 1;
    if (Command > 0xF || Command < 0) return 2;
    if (Price > 999999 || Price < 0) return 3;
    if (Volume > 999999 || Volume < 0) return 4;
    if (Error > 0xFF || Error < 0) return 5;
    if (Code > 0xFF || Error < 0) return 6;
    //SOH
    a[0] = 0x1;
    //TRK_NO
    a[1] = TRK_NO/16 + 48; //0..7
    a[2] = TRK_NO - (a[1] - 48)*16;
    if (a[2] > 9) a[2] += 55; //ABCDEF
    else a[2] += 48;
    //Command
    a[3] = Command;
    if (a[3] > 9) a[3] += 55;
    else a[3] += 48;
    //STX
    a[4] = 0x2;
    //Price
    long int devider = 100000;
    for (long int i = 0; i < 6; i++)
    {
        long int x = i + 5;
        a[x] = Price/devider + 48;
        Price = Price - devider * (a[x] - 48);
        devider /= 10;
    }
    //Volume
    devider = 100000;
    for (long int i = 0; i < 6; i++)
    {
        long int x = i + 11;
        a[x] = Volume/devider + 48;
        Volume = Volume - devider * (a[x] - 48);
        devider /= 10;
    }
    //Error
    a[17] = Error/16;
    Error -= a[17] * 16;
    if (a[17] > 9) a[17] += 55;
    else a[17] += 48;
    a[18] = Error;
    if (a[18] > 9) a[18] += 55;
    else a[18] += 48;
    //Code
    a[19] = Code/16;
    Code -= a[19] * 16;
    if (a[19] > 9) a[19] += 55;
    else a[19] += 48;
    a[20] = Code;
    if (a[20] > 9) a[20] += 55;
    else a[20] += 48;
    //ETX
    a[21] = 0x3;
    //CRC
    a[22] = a[1];
    long int i = 2;
    while(i < 22)
    {
        a[22] ^= a[i];
        i++;
    }
    return 0;
}
