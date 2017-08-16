#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 10;
const int Mod = 10086;

int notprime[N];
vector<int> primes;
int mu[N], smu[N];

void sieve(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			mu[i] = -1;
		}
		for(int t = 0; t < (int)primes.size(); t++) {
			int p = primes[t];
			int j = p * i;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				mu[j] = 0;
				break;
			} else {
				mu[j] = -mu[i];
			}
		}
	}
	for(int i = 1; i <= n; i++)
		smu[i] = ((smu[i-1] + 1LL * mu[i] * i) % Mod + Mod) % Mod;
}
inline int S(int n) {
	return (1LL * (1 + n) * n / 2) % Mod;
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
			int val = 1LL * (nd * S(md) + md * S(nd)) % Mod;
			ans = (ans + 1LL * ((smu[dd] - smu[d-1]) % Mod + Mod) % Mod * val % Mod) % Mod;
		}
		printf("%d\n", ans);
	}
}

