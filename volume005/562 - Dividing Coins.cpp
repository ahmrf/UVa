#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 105;

bool dp[105][N], vis[N];
int n, coins[105], half, sum;

void foo(int pos, int bar) {
	if(bar > sum) return ;
	if(pos == n) {
		vis[bar] = true;
		return ;
	}
	if(dp[pos][bar]) return ;
	dp[pos][bar] = vis[bar] = true;
	foo(pos + 1, bar + coins[pos]);
	foo(pos + 1, bar);
}

int main() {
	int cases;
	scanf("%d", &cases);
	for(int cc = 1; cc <= cases; cc++) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &coins[i]);
			sum += coins[i];
		}
		half = sum >> 1;
		foo(0, 0);
		int up = -1, down = 0;
		for(int i = half; i >= 0; i--) {
		   if(vis[i]) {
		      down = i;
		      break;
		   }
		}
		for(int i = half; i <= sum; i++) {
		   if(vis[i]) {
		      up = i;
		      break;
		   }
		}
		if(up != -1) {
		   if(up - half <= half - down) {
		      down = up;
		   }
		}
		printf("%d\n", abs(sum - down - down));
	}
	return 0;
}
