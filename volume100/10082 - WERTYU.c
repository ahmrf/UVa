#include<stdio.h>
#include<string.h>

int main ()
{
    char wrong [] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./";
    char right [] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    char ch;
    while(scanf("%c", &ch) == 1)
    {
        int i;
        if(ch == ' ') printf("%c", ch);
        else if(ch == '\n') printf("%c", ch);
        else
            for(i = 0; i < 43; i++)
            {
                if(ch == wrong[i])
                {
                    printf("%c", right[i]);
                    break;
                }
            }
    }

    return 0;
}
