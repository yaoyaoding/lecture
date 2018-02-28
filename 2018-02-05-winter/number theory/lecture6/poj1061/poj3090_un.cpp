#include <iostream>
using namespace std;

const int N = 1010;

int isnot[N], mu[N], smu[N], prm[N], ptot;

void init( int n ) {
	isnot[1] = true;
	mu[1] = 1;
	for( int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) {
			prm[++ptot] = i;
			mu[i] = -1;
		}
		for( int t = 1; t <= ptot; t++ ) {
			int j = prm[t] * i;
			isnot[j] = true;
			mu
		}
	}
}


