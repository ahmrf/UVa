#include<cstdio>

using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n;
        scanf("%d", &n);
        int *array = new int[n];
        for (int i = 0 ; i < n ; i++)
        scanf("%d", &array[i]);
        int countSwap = 0;

        for (int i = 0 ; i < n ; i++)
        {

            for (int j = i + 1 ; j < n ; j++)
            {
                if ( array[i] > array[j] ) countSwap++;
            }

        }

        printf("Optimal train swapping takes %d swaps.\n", countSwap);
        delete [] array;
    }
    return 0;
}
