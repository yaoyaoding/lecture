#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				int sub = gcd(i,j);
				ans += sub;
				ans %= 10086;
//				printf("%d ", sub);
			}
//			printf("\n");
		}

		printf("%d\n", ans);
	}
}

