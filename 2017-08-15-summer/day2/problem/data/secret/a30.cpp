
#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 10;

int n;
long long a[N];
long long c, d, m;

int main() {
	scanf("%d", &n);
	scanf("%lld%lld%lld%lld", &a[1], &c, &d, &m);
	for(int i = 2; i <= n; i++)  {
		a[i] = (a[i-1] * c + d) % m;
	}
	for(int i = 1; i <= n; i++ )
		printf("%lld ", a[i]);
	printf("\n");
	for(int i = n; i >= 1; i--) {
		for(int j = i + i; j <= n; j += i)
			a[i] -= a[j];
	}
	for(int i = 1; i <= n; i++ )
		printf("%lld ", a[i]);
	printf("\n");
	printf("%lld\n", a[1]);
}
