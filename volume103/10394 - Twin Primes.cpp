#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;
#define MAX 20000001

struct primePair{
    int a;
    int b;
};

vector<primePair> pairList;

bool p[MAX];

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i < sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i*i; j < MAX; j += (2*i))
        {
            p[j] = true;
        }
    }

}

void setPrimePair()
{
    for(int i = 1; i < MAX-2; ++i)
    {
        if(p[i] == false && p[i+2] == false)
        {
            primePair demo;
            demo.a = i;
            demo.b = i+2;
            pairList.push_back(demo);
        }
    }
    
}

int main (void)
{
    sieveMethod();
    setPrimePair();
    int n;

    while(scanf("%d", &n) != EOF)
    {
        n--;
        cout <<"(" <<pairList[n].a << ", " << pairList[n].b << ")" << endl;
    }

    return 0;

}

