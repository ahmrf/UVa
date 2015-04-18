#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    string hudai;
    getline(cin, hudai);
    map<string, int> myMap;
    vector<string> Names;
    while(cases--)
    {

        string country, name;
        cin >> country;
        getline(cin, name);

        if(myMap.find(country) == myMap.end()){
            myMap[country] = 1;
            Names.push_back(country);
        }
        else myMap[country]++;

    }

    sort(Names.begin(), Names.end());
    int n = Names.size();
    for(int i = 0; i < n; i++)
    {
        cout << Names[i] << " " << myMap[Names[i]] << endl;
    }
    return 0;
}
