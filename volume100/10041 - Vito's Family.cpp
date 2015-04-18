#include<algorithm>
#include<cstdio>
using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int N;
        scanf("%d", &N);
        int *street = new int[N];
        int *distance = new int[N];
        for(int i=0; i<N; i++)
        {
            scanf("%d", &street[i]);
        }
        sort(street, street+N);
        int minimum = 2147483647;
        for(int i=0; i<N; i++)
        {
            int dSum = 0;
            for(int j=0; j<N; j++)
            {
                dSum += abs(street[j]-street[i]);
            }
            if(dSum < minimum) minimum = dSum;
        }

        printf("%d\n", minimum);
    }
    return 0;
}
