#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int Mod = 1e9 + 7;

int n, m;
bool notprime[N];
int other[N], minpk[N], minp[N];
int power[N], f[N], inverse[N];
vector<int> primes;

int sieve() {
	inverse[1] = 1;
	for(int i = 2; i <= n; i++) {
		inverse[i] = - 1LL * (Mod / i) * inverse[Mod % i] % Mod;
		if(inverse[i] < 0) inverse[i] += Mod;
	}
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			other[i] = 1;
			minpk[i] = 1;
			minp[i] = i;
		}
		for(int t = 0; t < (int)primes.size(); t++) {
			int p = primes[t];
			int j = p * i;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				other[j] = other[i];
				minpk[j] = minpk[i] + 1;
				minp[j] = p;
				break;
			} else {
				other[j] = i;
				minpk[j] = 1;
				minp[j] = p;
			}
		}
	}
	f[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(other[i] != 1) {	//	p^k * c
			f[i] = 1LL * f[other[i]] * f[i / other[i]] % Mod;
		} else {	//	p^k
			if(minpk[i] == 1) {
				power[i] = i;
				for(int t = 1; t < m; t++)
					power[i] = 1LL * power[i] * i % Mod;
			}
			int k = minpk[i], p = minp[i];
			if(p == 2 && k == 2) {
				f[i] = i % Mod;
				for(int t = 1; t < m; t++)
					f[i] = 1LL * f[i] * i % Mod;
				f[i] = 1LL * f[i] * (k + 1 - p * k) % Mod;
				if(f[i] < 0) f[i] += Mod;
//				f[i] = Mod - 4;
//				f[i] = 1LL * power[p] * (k + 1 - p * k) % Mod;
//				if(f[i] < 0) f[i] += Mod;
			} else {
				f[i] = 1LL * f[i / p] * power[p] % Mod * (k + 1 - p * k) % Mod;
				if(f[i] < 0) f[i] += Mod;
				int down = k - p * k + p;
				if(down < 0) {
					f[i] = -1LL * f[i] * inverse[-down] % Mod;
					if(f[i] < 0) f[i] += Mod;
				} else {
					f[i] = 1LL * f[i] * inverse[down] % Mod;
					if(f[i] >= Mod) f[i] -= Mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += f[i];
		if(ans >= Mod) ans -= Mod;
//		printf("f(%d) = %d\n", i, f[i] > Mod/2 ? f[i] - Mod : f[i]);
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	printf("%d\n", sieve());
}

