#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, opt;
	scanf("%d%d", &T, &opt);
	while(T--) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long A = 0, B = 0;
		for(long long x = 0; a * x <= c; x++) {
			long long y = (c - a * x) / b;
			if(a * x + b * y == c) {
				A ++;
				B += x + y;
			}
		}
		if(opt == 1)
			printf("%lld\n", A);
		else
			printf("%lld %lld\n", A, B);
	}
}

