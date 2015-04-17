#include<stdio.h>

int no_of_terms(long long num)
{
    int count = 0;
    while(1)
    {
        if(num & 1) num = num*3 + 1;
        else num >>= 1;
        count++;
        if(num == 1) break;
    }

    return count;
}

int main (void)
{
    long long L, U, i, maxTerms, terms, ans;
    while(scanf("%lld%lld", &L, &U), L || U)
    {
        maxTerms = -1;
        ans = 0;
        if(L > U)
        {
            int temp = L;
            L = U;
            U = temp;
        }
        for(i=L; i<=U; i++)
        {
            terms = no_of_terms(i);
            if(terms > maxTerms)
            {
                maxTerms = terms;
                ans = i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, U, ans, maxTerms);
    }
    return 0;
}
