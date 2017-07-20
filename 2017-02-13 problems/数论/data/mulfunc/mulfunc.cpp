#include <cstdio>

const int N = 1000010;

bool isnot[N];
int prm[N], tau[N], sigma[N], mu[N], phi[N], ptot;

void init( int n ) {
	isnot[1] = true;
	tau[1] = 1;
	sigma[1] = 1;
	mu[1] = 1;
	phi[1] = 1;
	for( int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) {
			prm[ptot++] = i;
			tau[i] = 2;
			sigma[i] = i + 1;
			mu[i] = -1;
			phi[i] = i - 1;
		}

		for( int t = 0; t < ptot; t++ ) {
			int j = prm[t] * i;
			if( j > n ) break;
			isnot[j] = true;
			if( i % prm[t] == 0 ) {
				//	j = prm[t]^r * b
				int r = 1, a = prm[t], b = i;
				if( j == 999600 ) {
					r = 1;
				}
				while( b % prm[t] == 0 ) {
					r++;
					a *= prm[t];
					b /= prm[t];
				}
				tau[j] = (r + 1) * tau[b];
				sigma[j] = (a * prm[t] - 1) / (prm[t] - 1) * sigma[b];
				mu[j] = 0;
				phi[j] = (a - a/prm[t]) * phi[b];
				break;
			} else {
				tau[j] = tau[prm[t]] * tau[i];
				sigma[j] = sigma[prm[t]] * sigma[i];
				mu[j] = mu[prm[t]] * mu[i];
				phi[j] = phi[prm[t]] * phi[i];
			}
		}
	}
}

int main() {
	int opt;
	init(1000000);
	scanf( "%d", &opt );
	for( int i = 1; i <= 1000000; i++ ) {
		if( opt == 1 ) {
			printf( "%d%s", tau[i], (i != 1000000) ? " " : "\n" );
		} else if( opt == 2 ) {
			printf( "%d%s", sigma[i], (i != 1000000) ? " " : "\n" );
		} else if( opt == 3 ) {
			printf( "%d%s", mu[i], (i != 1000000) ? " " : "\n" );
		} else if( opt == 4 ) {
			printf( "%d%s", phi[i], (i != 1000000) ? " " : "\n" );
		} else if( opt == 5 ) {
			printf( "%d%s", (i == 1), (i != 1000000) ? " " : "\n" );
		} else {
			printf( "%d%s", i, (i != 1000000) ? " " : "\n" );
		}
	}
}

