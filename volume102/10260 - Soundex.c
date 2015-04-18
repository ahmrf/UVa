#include<stdio.h>
#include<string.h>

int code (char ch)
{
    if(ch == 'B' || ch == 'F' || ch == 'P' || ch == 'V') return 1;
    else if(ch=='C'||ch=='G'||ch=='J'||ch=='K'||ch=='Q'||ch=='S'||ch=='X'||ch=='Z') return 2;
    else if(ch=='D'||ch=='T') return 3;
    else if(ch=='L') return 4;
    else if(ch=='M'||ch=='N') return 5;
    else if(ch=='R') return 6;
    else return 0;
}

int main (void)
{
    char s[50];
    int i, l;
    while(gets(s))
    {
        l = strlen(s);
        for(i = 0; i < l; i++)
        {
            if(i != 0)
            {
                if(code(s[i]) == code(s[i-1])) ;
                else if(code(s[i])) printf("%d", code(s[i]));
            }

            else if(code(s[i])) printf("%d", code(s[i]));
        }
        printf("\n");
    }
    return 0;
}
