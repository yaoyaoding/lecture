#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int Mod = 1e9 + 7;

int mu[N], notprime[N];
vector<int> primes;
long long sigma[N], f[N], F[N];

long long mpow(long long a, int b) {
	long long rt;
	for(rt = 1; b; b>>=1,a=(a*a)%Mod)
		if(b&1) rt=(rt*a)%Mod;
	return rt;
}
void sieve(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			mu[i] = -1;
		}
		for(int p : primes) {
			int j = i * p;
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
}
long long solve(int n, int m) {
	for(int i = 1; i <= n; i++) {
		sigma[i] = 0;
		for(int j = 1; j <= i; j++) {
			if(i % j == 0)
				sigma[i]++;
		}
		f[i] = 0;
		for(int j = 1; j <= i; j++) {
			if(i % j) continue;
			f[i] = (f[i] + sigma[j] * mu[i / j] * (i / j)) % Mod;
			if(f[i] < 0) f[i] += Mod;
		}
		f[i] = f[i] * mpow(i, m) % Mod;
//		printf("f(%d) = %lld\n", i, f[i] > Mod/2 ? f[i] - Mod : f[i]);
		F[i] = (F[i-1] + f[i]) % Mod;
	}
	return F[n];

}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	sieve(1e6);
	printf("%lld\n", solve(n,m));
}

