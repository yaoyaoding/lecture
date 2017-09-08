#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
const int Mod = 1e9 + 7;

typedef long long dint;

dint fac[N], vfac[N];

dint mpow(dint a, int b) {
	dint rt;
	for(rt = 1; b; b>>=1,a=(a*a)%Mod)
		if(b & 1) rt = (rt*a) % Mod;
	return rt;
}
void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) 
		fac[i] = fac[i - 1] * i % Mod;
	vfac[n] = mpow(fac[n], Mod - 2);
	for(int i = n - 1; i >= 0; i--)
		vfac[i] = vfac[i + 1] * (i + 1) % Mod;
}
dint comb(int n, int m) {
	if(m < 0 || m > n) return 0;
	return fac[n] * vfac[m] % Mod * vfac[n - m] % Mod;
}
int main() {
	init(2e6);
	int T;
	scanf("%d", &T);
	while(T--) {
		int dir, n, m;
		scanf("%d%d%d", &dir, &n, &m);
		if(dir == 1) {
			printf("%d\n", (int)comb(n + 1, m + 1) );
		} else if(dir == 2) {
			if(n + 1 == m)
				printf("%d\n", 0);
			else
				printf("%d\n", (int)comb(n + 1, m) );
		}
	}
}

