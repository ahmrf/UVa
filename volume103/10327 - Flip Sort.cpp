#include<cstdio>

using namespace std;

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        int *array = new int[n];
        for (int i = 0 ; i < n ; i++)
        scanf("%d", &array[i]);
        int countFlip = 0;

        for (int i = 0 ; i < n ; i++)
        {

            for (int j = i + 1 ; j < n ; j++)
            {
                if ( array[i] > array[j] ) countFlip++;
            }

        }

        printf("Minimum exchange operations : %d\n", countFlip);
        delete [] array;
    }
    return 0;
}
