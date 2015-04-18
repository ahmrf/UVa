
#include <iostream>     
#include <algorithm>    
#include <cstdio>
#include<string>
#include<vector>

using namespace std;

int main () {

    int cases, case_no = 0;
    scanf("%d", &cases);
    while(cases--){
        string mychars;
        cin >> mychars;
        int n = mychars.length();
        sort (mychars.begin(), mychars.end());

        vector<string>res;

        do {
            cout << mychars << endl;
        } while ( next_permutation(mychars.begin(), mychars.end()));

        cout << endl;
    }
  return 0;
}




