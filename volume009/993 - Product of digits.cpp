#include<cstdio>
#include<algorithm>


using namespace std;

int main (void)
{
    int cases;
    long long int num;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld", &num);
        if(num < 10) printf("%lld\n", num);
        else
        {
            int a[20];
            int div = 9, c = 0, i;
            while(div>1)
            {
                if(num%div==0)
                {
                    while(num%div==0)
                    {
                        a[c++] = div;
                        num/=div;
                    }
                }
                div--;

            }

            if(num !=1) printf("-1\n");
            else
            {
                sort(a, a+c);
                for(i=0; i<c;i++) printf("%d", a[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
