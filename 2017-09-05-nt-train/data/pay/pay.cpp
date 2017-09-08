#include <bits/stdc++.h>
using namespace std;

typedef long long dint;

void exgcd(dint a, dint b, dint &d, dint &x, dint &y) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
		return;
	} else {
		long long xx, yy;
		exgcd(b, a % b, d, xx, yy);
		//	b * xx + (a - (a/b)*b) * yy = d
		//	a * yy + b * (xx - (a/b) * yy) = d
		x = yy;
		y = xx - (a/b) * yy;
	}
}
dint ceil(dint a, dint b);
dint floor(dint a, dint b) {
	if(a >= 0) 
		return a / b;
	else
		return -ceil(-a,b);
}
dint ceil(dint a, dint b) {
	if(a >= 0)
		return (a + b - 1) / b;
	else
		return -floor(-a,b);
}

int main() {
	int T, opt;
	scanf("%d%d", &T, &opt);
	while(T--) {
		dint a, b, c, d, x, y;
		scanf("%lld%lld%lld", &a, &b, &c);
		exgcd(a,b,d,x,y);
		long long A = 0, B = 0;
		if(c % d != 0) {
			A = B = 0;
		} else {
			x *= c / d;
			y *= c / d;
			long long dx = b / d;
			long long dy = a / d;
			long long kmin = ceil(-x, dx);
			long long kmax = floor(y, dy);
			/*
			for(long long k = kmin; k <= kmax; k++) {
				A++;
				B += x + k * dx + y - k * dy;
			}
			*/
			A = kmax - kmin + 1;
			B = A * (x + y) + (kmin + kmax) * A / 2 * (dx - dy);
		}
		if(opt == 1)
			printf("%lld\n", A);
		else
			printf("%lld %lld\n", A, B);
	}
}


