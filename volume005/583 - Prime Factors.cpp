#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

#define MAX 50000

int main (void)
{
    vector <int> primeNumbers;
    bool ifPrime[100000];

    ifPrime[0] = ifPrime[1] = true;
    for(long long i = 2; i <= MAX; i++)
    {
        if(ifPrime[i] == true) continue;
        for(long long j = i*i; j <= MAX; j += i)
        {
            ifPrime[j] = true;
        }
        primeNumbers.push_back((int)i);
    }
    int num, s;

    while(scanf("%d", &num), num)
    {
        int number = num;
        if(num < 0) num *= -1;
        vector<int>PFactors;
        int i = 0;
        long pf = primeNumbers[i];
        while(pf*pf <= num)
        {
            while(num % pf == 0)
            {
                num /= pf;
                PFactors.push_back(pf);
            }
            pf = primeNumbers[++i];
        }
        if(num != 1) PFactors.push_back(num);
        s = PFactors.size();
        printf(number < 0? "%d = -1 x %d" : "%d = %d", number, PFactors[0]);
        for(int i = 1; i < s; i++)
        {
            printf(" x %d", PFactors[i]);
        }
        printf("\n");
    }
    return 0;
}

