#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 10;
const int Mod = 10086;

int notprime[N];
vector<int> primes;
int ph[N], sph[N];

void sieve(int n) {
	ph[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			ph[i] = i - 1;
		}
		for(int t = 0; t < (int)primes.size(); t++) {
			int p = primes[t];
			int j = p * i;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				ph[j] = ph[i] * p;
				break;
			} else {
				ph[j] = ph[i] * (p - 1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		sph[i] = sph[i-1] + ph[i] % Mod;
		if(sph[i] >= Mod) sph[i] -= Mod;
	}
}
int main() {
	int T;
	sieve(10000000);
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int d = 1, dd; d <= n && d <= m; d = dd + 1) {
			dd = min(n/(n/d),m/(m/d));
			int nd = n / d;
			int md = m / d;
			int val = 1LL * (sph[dd] - sph[d-1]) * nd % Mod * md % Mod;
			if(val < 0) val += Mod;
			ans = (ans + val) % Mod;
		}
		printf("%d\n", ans);
	}
}

