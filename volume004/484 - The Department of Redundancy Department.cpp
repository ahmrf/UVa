#include<map>
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<vector>
using namespace std;

int main (void)
{
    map<int, int> myMap;
    vector<int>numbers;

    int n;

    while(scanf("%d", &n) != EOF)
    {
        if(myMap.find(n) == myMap.end())
        {
            numbers.push_back(n);
            myMap[n] = 1;
        }

        else myMap[n]++;

    }

    for(int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " " << myMap[numbers[i]] << endl;
    }

    return 0;
}
