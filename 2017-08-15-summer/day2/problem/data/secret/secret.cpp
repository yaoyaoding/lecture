#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 10;

int n;
int mu[N];
int notprime[N];
vector<int> primes;
long long a[N];
long long c, d, m;

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
}
int main() {
	scanf("%d", &n);
	scanf("%lld%lld%lld%lld", &a[1], &c, &d, &m);
	sieve(int(1e7));
	for(int i = 2; i <= n; i++) 
		a[i] = (a[i-1] * c + d) % m;
	long long ans = 0;
	/*
	for(int i = n; i >= 1; i--)
		for(int j = i + i; j <= n; j+=i)
			a[i] -= a[j];
	ans = a[1];
	*/
	for(int i = 1; i <= n; i++)
		ans += mu[i] * a[i];
	printf("%lld\n", ans);
}

