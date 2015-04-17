#include <bits/stdc++.h>

using namespace std;

int char_value(char ch) {
	if(ch <= '9') return ch-48;
	return ch-55;
}

char int_value(int a) {
	if(a < 10) return a+'0';
	return (a-10)+'A';
}

string add(string a, string b, int base) {
	int sl = a.length(), carry = 0, sum;
	string ret;
	while(sl--) {
		sum = carry + char_value(a[sl]) + char_value(b[sl]);
		ret = int_value(sum % base) + ret;
		carry = sum / base;
	}

	if(carry > 0) ret = int_value(carry) + ret;
	return ret;

}

string reversed(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	string num, sum, N;
	while(cin >> N) {
		int lowest_base = 0;
		int sl = N.length();
		for(int i = 0; i < sl; i++)
			lowest_base = max(lowest_base, char_value(N[i]));
		if(lowest_base == 0) lowest_base++;
		for(int base = 15; base > lowest_base; base--) {
			int steps = 0;
			num = N;
			while(true) {
				if(num == reversed(num)) break;
				sum = add(num, reversed(num), base);
				num = sum;
				steps++;
			}
			if(base != 15) printf(" ");
			printf("%d", steps);
		}
		for(int i = lowest_base; i > 1; i--) { 
			if(i != 15) printf(" ");
			printf("?");
		}
		puts("");
	}
	return 0;
}