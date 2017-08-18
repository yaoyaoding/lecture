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
				int sub = 0;
				if(gcd(i,j) == 1) {
					ans += i + j;
					ans %= 10086;
					sub = i + j;
				}
//				printf("%d ", sub);
			}
//			printf("\n");
		}

		printf("%d\n", ans);
	}
}

