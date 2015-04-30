#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 200000

int p[MAX];

void sieveMethod()
{
    memset(p, 0, sizeof(p));
    p[0] = p[1] = 0;
    int i, j;

    for(i = 4; i < MAX; i += 2)
    {
        p[i] = 1;
    }

    int sq = sqrt(MAX);

    for(i = 3; i < sq; i+=2)
    {
        if(p[i] == 1) continue;
        for(j = i*i; j < MAX; j += 2*i)
        {
            p[j] = 1;
        }
    }

}

int value(char ch)
{
    int as = ch;
    if(as <= 90 && as >= 65) return as - 38;
    else return as - 96;
}

int sum (char charArray[])
{
    int l = strlen(charArray);
    int total = 0, i;
    for(i = 0; i < l; i++)
    {
        total += value(charArray[i]);
    }
    return total;
}


int main (void)
{
    sieveMethod();
    char ch[100];
    while(gets(ch))
    {
        int total = sum(ch);
        if(p[total] == 1) printf("It is not a prime word.\n");
        else printf("It is a prime word.\n");
    }
    return 0;
}
