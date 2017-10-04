#include "tpk172.h"

void formBuf(char *a, int TRK_NO, int Command, int Price, int Volume,int Status, int Error, int Code)
{
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
    int devider = 100000;
    for (int i = 0; i < 6; i++)
    {
        int x = i + 5;
        a[x] = Price/devider + 48;
        Price = Price - devider * (a[x] - 48);
        devider /= 10;
    }
    //Volume
    devider = 100000;
    for (int i = 0; i < 6; i++)
    {
        int x = i + 11;
        a[x] = Volume/devider + 48;
        Volume = Volume - devider * (a[x] - 48);
        devider /= 10;
    }
    //Status
    devider = 1000;
    for (int i = 0; i < 4; i++)
    {
        int x = i + 17;
        a[x] = Status/devider;
        Status -= devider*a[x];
        if (a[x] > 9) a[x] += 55;
        else a[x] += 48;
        devider /= 10;
    }
    //Error
    a[21] = Error/16;
    Error -= a[21] * 16;
    if (a[21] > 9) a[21] += 55;
    else a[21] += 48;
    a[22] = Error;
    if (a[22] > 9) a[22] += 55;
    else a[22] += 48;
    //Code
    a[23] = Code/16;
    Code -= a[23] * 16;
    if (a[23] > 9) a[23] += 55;
    else a[23] += 48;
    a[24] = Code;
    if (a[24] > 9) a[24] += 55;
    else a[24] += 48;
    //ETX
    a[25] = 0x3;
    //CRC
    a[26] = a[1];
    for (int i = 2; i < 27; i++)
    {
        a[26] ^= a[i];
    }
}
