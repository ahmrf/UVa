#include<bits/stdc++.h>

using namespace std;
long long Z,I,M;

int main()
{
    long long L,no=0;
    while(scanf("%lld%lld%lld%lld", &Z, &I, &M, &L) != EOF)
    {
        if(Z == 0 && I == 0 && M == 0 && L == 0) break;
        long long same, c=0;
        map<long long,int>mp;
        while(1)
        {
            same = ((Z*L)+I) %M;
            mp[same]++;
            if(mp[same] == 2) break;
            L = same;
            c++;
        }
        printf("Case %lld: %lld\n",++no,c);
    }
    return 0;
}
