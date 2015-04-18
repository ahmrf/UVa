#include<cstdio>
using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        int n, i, sum = 0;
        scanf("%d", &n);
        int *grade = new int[n];
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &grade[i]);
            sum += grade[i];
        }

        double avg = (double)(sum/n);
        int count = 0;
        for(i = 0; i < n; ++i)
        {
            if((double)grade[i] > avg) count++;
        }

        printf("%.3lf%%\n", ((double)count*100.00/(double)n));
        delete [] grade;
    }
}

