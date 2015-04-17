#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

int len;
struct DNA
{
    char str[105];
    int inversions;
} dna[103];

int measureInversion(char *str)
{
    int ci = 0;
    for(int i = 0; i<len-1; i++)
        for(int j = i+1; j < len; j++)
            if(str[i] > str[j]) ci++;

    return ci;
}

bool ifSwap(DNA a, DNA b)
{

    return (a.inversions < b.inversions)? true : false;
}

int main()
{
    int cases, n;

    bool enter = false;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &len, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", dna[i].str);
            dna[i].inversions = measureInversion(dna[i].str);
        }

        stable_sort(dna, dna + n, ifSwap);
        if(enter) printf("\n");
        for(int i = 0; i < n; i++)
            printf("%s\n", dna[i].str);

        enter = true;
    }
    return 0;
}

