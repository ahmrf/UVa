#include<cstdio>
#include<cstring>
#include<vector>
#define maxN 1000001

using namespace std;

bool isp[maxN];
int ans[maxN];
vector<int> prime;

void getprimes()
{
    memset(isp, true, sizeof(isp));
    isp[0] = isp[1] = false;
    for(int i = 4; i<maxN; i+=2) isp[i] = false;
    for(int i = 3; i<1001; i+=2)
    {
        if(isp[i])
        {
            for(int j=i*i; j<maxN; j+=2*i)
                isp[j] = false;
        }
    }
    prime.push_back(2);
    for(int i=3; i<maxN; i+=2)
    {
        if(isp[i])
        {
            prime.push_back(i);
        }
    }

}

void PreCalculate()
{
    getprimes();
    ans[1] = 0;
    for (int i=2; i<maxN; i++)
    {
        ans[i] = ans[i-1];
        int n = i, j = 0;
        while (!isp[n])
        {
            if (n%prime[j]==0)
            {
                ans[i]++;
                n /= prime[j];
            }
            else j++;
        }
        if (isp[n]) ans[i]++;
    }
}

int main (void)
{

    PreCalculate();
    int N;
    while(scanf("%d", &N) != EOF) printf("%d\n", ans[N]);
    return 0;
}

