#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#define maxN 1000001

#define pb push_back

using namespace std;

bool isP[maxN+1];
int dP[maxN+1];


int sum_of_digit(int num)
{
    int total = 0;
    while(num)
    {
        total += num%10;
        num /= 10;
    }
    return total;
}

void Sieve() {
    memset(isP, true, sizeof(isP));
    isP[0] = isP[1] = false;

    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;

    int t= 0;
    for (int i=0; i<maxN; i++)
    {
        if(isP[i])
        {
            if(isP[sum_of_digit(i)]) t++;
        }
        dP[i] = t;
    }

}


int main (void)
{
    Sieve();
    int a, b, cases, c;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &a, &b);

        c = (dP[b] - dP[a-1]);
        printf("%d\n", c);
    }

    return 0;
}

