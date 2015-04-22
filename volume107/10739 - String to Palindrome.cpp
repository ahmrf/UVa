#include <bits/stdc++.h>
using namespace std;

char s[1010];
int dP[1010][1010];

int f(int i, int j) {
	if(dP[i][j] != -1) return dP[i][j];
	if(i == j) return dP[i][j] = 0;
	if(i+1 == j) {
		if(s[i]==s[j])return dP[i][j]=0;
		return dP[i][j] = 1;
	}
	if(s[i]!=s[j]){
		int x = min(1 + f(i+1,j), 1 + f(i, j-1));
		return dP[i][j] = min(x, 1 + f(i+1, j-1));
	}
	return dP[i][j] = f(i+1, j-1);
}

int main() {
	int testcase, sl;
	scanf("%d", &testcase);
	for(int c = 1; c <= testcase; c++) {
		scanf("%s", s);
		sl = strlen(s);
		for(int i = 0; i < sl; i++)
			for(int j = 0; j < sl; j++)
				dP[i][j] = -1;
		printf("Case %d: %d\n", c, f(0, sl-1));
	}
	return 0;
}