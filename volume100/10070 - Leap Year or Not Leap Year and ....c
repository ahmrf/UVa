#include<stdio.h>
#include<string.h>

int main (void)
{
    char year[100000];
    int size, mod4, mod15, mod55, mod100, mod400, i, flag = 0;
    while(gets(year))
    {
        size = strlen(year);
        mod4 = mod15 = mod55 = mod100 = mod400 = 0;
        for(i = 0; i < size; i++)
        {
            mod4 = (mod4*10 + year[i]-'0') % 4;
            mod15 = (mod15*10 + year[i]-'0') % 15;
            mod55 = (mod55*10 + year[i]-'0') % 55;
            mod100 = (mod100*10 + year[i]-'0') % 100;
            mod400 = (mod400*10 + year[i]-'0') % 400;
        }
        if(flag) printf("\n");
        if ((mod4 == 0 && mod100) || mod400 == 0)
        {
            printf("This is leap year.\n");
            if (mod15 == 0)
                printf("This is huluculu festival year.\n");
            if (mod55 == 0)
                printf("This is bulukulu festival year.\n");
        }
        else
        {
            if (mod15 == 0)
                printf("This is huluculu festival year.\n");
            else
                printf("This is an ordinary year.\n");
        }

        flag = 1;
    }


    return 0;
}
