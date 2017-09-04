#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const double eps = 1e-7;

int n, q;
double a[N], b[N], c[N];

double F( double x ) {
	double y = 1e100;
	double xx = x * x;
	for(int i = 0; i < n; i++) 
		y = min(y, a[i] * xx + b[i] * x + c[i]);
	return y;
}
inline double simpson( double a, double b, double fa, double fb, double fc ) {
	return (fa+4*fc+fb)*(b-a)/6;
}
double adapt( double a, double b, double c, double fa, double fb, double fc ) {
	double d = (a+c)/2, e = (c+b)/2;
	double fd = F(d), fe = F(e);
	double sa = simpson(a,c,fa,fc,fd);
	double sb = simpson(c,b,fc,fb,fe);
	double ss = simpson(a,b,fa,fb,fc);
	if( fabs(sa+sb-ss)<eps ) return sa+sb;
	return adapt(a,c,d,fa,fc,fd)+adapt(c,b,e,fc,fb,fe);
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf%lf", a + i, b + i, c + i);
	for(int i = 0; i < q; i++) {
		double L, R;
		scanf("%lf%lf", &L, &R);
		printf("%.3f\n", adapt(L,R,(L+R)/2.0,F(L),F(R),F((L+R)/2.0)));
	}
}

