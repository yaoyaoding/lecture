#include <bits/stdc++.h>
using namespace std;

#define rank NIHAOYA

vector<pair<int,int> > factor(int n) {
	vector<pair<int,int> > fac;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			fac.push_back(pair<int,int>(i,0));
			while(n % i == 0) {
				fac.back().second++;
				n /= i;
			}
		}
	}
	if(n != 1) {
		fac.push_back(pair<int,int>(n, 1));
	}
	return fac;
}
int varphi(vector<pair<int,int> > fac) {
	int rt = 1;
	for(int t = 0; t < fac.size(); t++) {
		for(int tt = 0; tt < fac[t].second; tt++) {
			if(tt == 0)
				rt *= fac[t].first - 1;
			else
				rt *= fac[t].first;
		}
	}
	return rt;
}
int mpow(int a, int b, int m) {
	int rt;
	for(rt = 1; b; b>>=1,a=(1LL*a*a)%m)
		if(b&1) rt=(1LL*rt*a)%m;
	return rt;
}
int rank(int a, int m) {
	if(m == 1) return 1;

	int phi = varphi(factor(m));
	int rt = phi;
	for(int i = 1; i * i <= phi; i++) {
		if(phi % i == 0) {
			if(mpow(a,i,m) == 1) rt = min(rt, i);
			if(mpow(a,phi/i,m) == 1) rt = min(rt, phi/i);
		} 
	}
	return rt;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, m;
		scanf("%d%d", &a, &m);
		printf("%d\n", rank(a,m));
	}
}

