#include <bits/stdc++.h>

using namespace std;

const int N = 2123456;
const int MOD = 1000000007;

int cost[21][21], k[21], dp[21][205], n, tot, mx;
bool vis[21][205];

int call(int pos, int val) {
	if(val > tot) {
		return -1;
	}
	if(pos == n) {
		return val;
	}
	if(vis[pos][val]) {
		return dp[pos][val];
	}
	vis[pos][val] = true;
	int res = -1;
	for(int i = 0; i < k[pos]; i++) {
		res = max(res, call(pos + 1, val + cost[pos][i]));
	}
	return dp[pos][val] = res;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for(int cc = 1; cc <= cases; cc++) {
		scanf("%d %d", &tot, &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &k[i]);
			for(int j = 0; j < k[i]; j++) {
				scanf("%d", &cost[i][j]);
			}
		}
		memset(vis, 0, sizeof(vis));
		mx = call(0, 0);
		if(mx == -1) {
			puts("no solution");
		}
		else {
			printf("%d\n", mx);
		}
	}
	return 0;
}
