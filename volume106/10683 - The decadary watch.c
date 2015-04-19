#include<stdio.h>

int main (void)
{
    int h, m, s, cs;
    long long traditional;
    const long long deca = 10000000;
    const long long tradi = 8640000;
    char time[9];

    while(gets(time))
    {
        h = (time[0] - '0')*10 + time[1] - '0';
        m = (time[2] - '0')*10 + time[3] - '0';
        s = (time[4] - '0')*10 + time[5] - '0';
        cs = (time[6] - '0')*10 + time[7] - '0';

        traditional = h*360000 + m*6000 + s*100 + cs;
        printf("%07lld\n", (traditional * deca)/tradi);
    }

    return 0;
}
