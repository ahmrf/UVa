#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int price[N], weight[N], can, dp[35], n, m;

void fileIO() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


int main() {
	//fileIO();
	int cases;
	scanf("%d", &cases);
	for(int cc = 1; cc <= cases; cc++) {
		scanf("%d", &n);
		long long res = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &price[i], &weight[i]);
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			for(int j = 35; j > 0; j--) {
				if(weight[i] <= j) {
					dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
				}
			}
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &can);
			res += dp[can];
		}
		printf("%lld\n", res);
	}
	return 0;
}
