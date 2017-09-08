#include <bits/stdc++.h>
using namespace std;

long long getk(long long p, long long a) {
	if(a == 0) return 0;
	return getk(p, a / p) + a / p;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		long long l, r, n;
		scanf("%lld%lld%lld", &l, &r, &n);
		long long ans = 0;
		for(long long i = l; i <= r; i++) {
			long long k5 = getk(5, n) - getk(5, i) - getk(5, n-i);
			if(k5 >= 1) ans++;
		}
		printf("%lld\n", ans);
	}
}

