#include <bits/stdc++.h>

using namespace std;

char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int decimal[] = {1, 5, 10, 50, 100, 500, 1000};
map<string, int> store;

int main() {
	for(int i = 1; i < 4000; i++) {
		string s;
		int leftdigit, first, last, n = i;
		
		while(n > 0) {
			for(first = 6; first > 0; first--) {
				if(n >= decimal[first])
					break;
			}

			for(last = 0; last < 7; last++) {
				if(n <= decimal[last])
					break;
			}
			leftdigit = n;
			while(leftdigit) {
				if(leftdigit < 10) break;
				leftdigit /= 10;
			}

			if(n < 10 && n == 4) {
				s = s + roman[first] + roman[last];
				n = 0;
			}
			else if(n > 10 && leftdigit == 4) {
				s = s + roman[first] + roman[last];
				n -= (decimal[last] - decimal[first]);
			}
			else if(n < 10 && n == 9) {
				s = s + roman[first-1] + roman[last];
				n = 0;
			}
			else if(n > 10 && leftdigit == 9) {
				s = s + roman[first-1] + roman[last];
				n -= (decimal[last] - decimal[first-1]);
			}
			else{
				s = s + roman[first];
				n -= decimal[first];
			}
		}

		store[s] = i;
	}

	string str;
	while(cin >> str) {
		if(store.find(str) == store.end()) 
			cout << "This is not a valid number" << endl;
		else cout << store[str] << endl;
	}
	return 0;
}