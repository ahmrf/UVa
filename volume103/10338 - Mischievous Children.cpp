#include<map>
#include<cstdio>
#include<cstring>

using namespace std;

int main (void)
{
    long long Factorial[21];
    Factorial[0] = Factorial[1] = 1;
    for(int i=2; i<=20; ++i)
    {
        Factorial[i] = Factorial[i-1]*i;
    }

    int cases;
    scanf("%d\n", &cases);
    for(int c=1; c<= cases; c++)
    {
        char wrd[25];
        gets(wrd);
        map<char, int> m;
        int lngth = strlen(wrd);
        long long ans = Factorial[lngth];
        for(int i=0; i<lngth; i++)
        {
            if(m.find(wrd[i]) == m.end()) m[wrd[i]] = 1;
            else m[wrd[i]]++;
        }

        for(int i=0; i<lngth; i++)
        {
            if(m[wrd[i]]==0) continue;
            ans/=Factorial[m[wrd[i]]];
            m[wrd[i]] = 0;
        }

        printf("Data set %d: %lld\n", c, ans);
    }

    return 0;
}

