#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main (void)
{
    long long int value;
    vector<long long int> data;

    while(scanf("%lld", &value) == 1)
    {
        data.insert(data.begin(), value);
        sort(data.begin(), data.end());
        int length = data.size();
        int index = length/2;
        if(length%2 == 0){
            printf("%lld\n", (data[index] + data[index-1])/2);
        }

        else printf("%lld\n", data[index]);
    }

    return 0;
}
