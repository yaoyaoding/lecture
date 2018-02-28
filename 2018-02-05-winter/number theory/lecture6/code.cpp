#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;

bool isnot[N];
int mu[N], phi[N];
int primes[N], ptot;

void normal_sieve( int n ) {
	isnot[1] = true;
	for( register int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) {
			for( register int j = i + i; j <= n; j += i ) {
				isnot[j] = true;
			}
		}
	}
}
void linear_sieve( int n ) {
	isnot[1] = true;
	for( int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) 
			primes[ptot++] = i;
		for( int t = 0; t < ptot; t++ ) {
			int j = primes[t] * i;
			if( j > n ) break;
			isnot[j] = true;
			if( i % primes[t] == 0 ) 
				break;
		}
	}
}
void linear_sieve_more( int n ) {
	isnot[1] = true;
	mu[1] = 1;
	phi[1] = 1;
	for( int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) {
			primes[ptot++] = i;
			mu[i] = -1;
			phi[i] = i - 1;
		}
		for( int t = 0; t < ptot; t++ ) {
			int j = primes[t] * i;
			if( j > n ) break;
			isnot[j] = true;
			mu[j] = mu[primes[t]] * mu[i];
			phi[j] = phi[primes[t]] * phi[i];
			if( i % primes[t] == 0 ) {
				mu[j] = 0;
				phi[j] = primes[t] * phi[i];
				break;
			}
		}
	}
}

//	greatest common divisor
long long gcd( long long a, long long b ) {	
	return b == 0 ? a : gcd( b, a % b );
}

long long lcm( long long a, long long b ) {
	return a / gcd(a,b) * b;
}

//	gcd(a,b) = a * x + b * y
long long exgcd( long long a, long long b, long long &x, long long &y ) {
	if( b == 0 ) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long x0, y0;
		long long cd = exgcd( b, a % b, x0, y0 );
		x = y0;
		y = x0 - (a/b) * y0;
		return cd;
	}
}
int main() {
	int a, b;
	while( scanf("%d%d",&a,&b) == 2 ) {
		long long x, y;
		long long cd = exgcd(a,b,x,y);
		printf( "%lld = %d * %lld + %d * %lld\n", cd, a, x, b, y );
	}
}

//	ax + by = c
bool linear_equation( long long a, long long b, long long c, long long &x, long long &y, long long &xinc, long long &yinc ) {
	long long d = gcd(a,b);
	if( c % d != 0 ) return false;
	a /= d, b /= d, c /= d;
	exgcd( a, b, x, y );
	x *= c;
	y *= c;
	xinc = b;
	yinc = -a;
	return true;
}

//	a^(-1) 
long long inverse( long long a, long long mod ) {
	long long x, y;
	exgcd( a, mod, x, y );
	return (x % mod + mod) % mod;
}

//	Chinese Remainder Theorem
//	x = a ( mod m )
long long crt( vector<long long> va, vector<long long> vm ) {
	int n = (int)va.size();
	long long summ = 1;
	for( int t = 0; t < n; t++ )
		summ *= vm[t];
	long long ans = 0;
	for( int t = 0; t < n; t++ ) {
		long long mi = summ / vm[t];
		long long invmi = inverse(mi,vm[t]);
		ans += mi * invmi %summ * va[t] % summ;
		if( ans >= summ ) ans -= summ;
	}
	return ans;
}

//	lucas't theorem
//	C(n,m) = C(n / p, m / p) * C(n % p, m % p) ( mod p )	when 0 <= m <= n
//	C(n,m) = 0 ( mod p )	when m > n
long long comb( long long n, long long m, long long p ) {
	if( m > n ) return 0;
	return fac[n] * vfac[m] % p * vfac[n-m] % p;
}
long long lucas( long long n, long long m, long long p ) {
	if( m > n ) return 0;
	if( n / p == 0 ) return 1;
	return lucas( n / p, m / p ) * comb( n % p, m % p ) % p;
}

