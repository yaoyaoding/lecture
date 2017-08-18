#include <bits/stdc++.h>
using namespace std;

struct FFT {
	typedef complex<double> Complex;
	Complex w[33];

	FFT() {
		double dpi = 2.0 * acos(-1);
		for(int p = 0; p <= 30; p++) 
			w[p] = Complex(cos(dpi/(1<<p)),sin(dpi/(1<<p)));
	}
	int reverse( int pmax, int a ) {
		int b = 0;
		for( int i=0; i<pmax; i++ ) 
			if( a&(1<<i) ) b |= 1<<(pmax-1-i);
		return b;
	}
	void fft( vector<Complex> &a, int pmax, bool r ) {
		int n = (int)a.size();;
		for( int i=0; i<n; i++ ) {
			int j=reverse(pmax,i);
			if( i<j ) swap(a[i],a[j]);
		}
		for( int p=1; p<=pmax; p++ ) {
			for( int i=0; i<n; i+=(1<<p) ) {
				Complex wo, wk;
				int l = 1<<(p-1);
				if( !r ) wo = w[p];
				else wo = conj(w[p]);
				wk = w[0];
				for( int j=0; j<l; j++,wk=wk*wo ) {
					Complex lf = a[i+j], rg = a[i+j+l];
					a[i+j] = lf + wk*rg;
					a[i+j+l] = lf - wk*rg;
				}
			}
		}
		if( r ) for( int i=0; i<n; i++ ) 
			a[i].real(a[i].real()/n);
	}
	vector<double> multiply( vector<double> a, vector<double> b ) {
		int pmax;
		for( pmax = 0; a.size() > (1u<<pmax) || b.size() > (1u<<pmax); pmax++ );
		pmax++;
		vector<Complex> ca, cb, cc;
		for( int t = 0; t < (int)a.size(); t++ )
			ca.push_back(Complex(a[t],0));
		for( int t = 0; t < (int)b.size(); t++ )
			cb.push_back(Complex(b[t],0));
		ca.resize(1<<pmax);
		cb.resize(1<<pmax);
		cc.resize(1<<pmax);
		fft( ca, pmax, 0 );
		fft( cb, pmax, 0 );
		for( int t = 0; t < (int)cc.size(); t++ ) 
			cc[t] = ca[t] * cb[t];
		fft( cc, pmax, 1 );
		vector<double> c;
		for( int t = 0; t < (int)cc.size(); t++ )
			c.push_back(cc[t].real());
		return c;
	}
}fft;

const int N = 500000 + 10;

int n;
char ss[N];
vector<double> va, vb, vc;
bool ans[N];

int main() {
	int T;
//	scanf("%d", &T);
	T = 1;
	for( int cas = 1; cas <= T; cas++ ) {
		scanf("%d", &n);
		scanf("%s", ss);
		va.resize(n), vb.resize(n);
		for(int i = 0; i < n; i++) {
			if(ss[i] == 'a') {
				va[i] = 1.0;
				vb[i] = 0.0;
			} else if(ss[i] == 'b') {
				va[i] = 0.0;
				vb[i] = 1.0;
			} else {
				va[i] = vb[i] = 0.0;
			}
		}
		reverse(va.begin(), va.end());
		vc = fft.multiply(va, vb);

		for(int i = 0; i <= n; i++ )
			ans[i] = false;
		for(int i = 0; i < n + n - 1; i++) {
			bool exist = fabs(vc[i]) > 0.4;
			int dif = abs(n - 1 - i);
			if(exist) ans[dif] = true;
		}
		for(int i = 1; i < n; i++) {
			for(int j = i + i; j < n; j += i) {
				if(ans[j]) {
					ans[i] = true;
					break;
				}
			}
		}
		int tot = 0;
		for(int i = 1; i < n; i++)
			tot += (ans[i] == false);
		printf("%d\n", tot + 1);
		for(int i = 1; i < n; i++)
			if(ans[i] == false) printf("%d ", i);
		printf("%d\n", n);
	}
}

