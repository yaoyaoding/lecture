#include <bits/stdc++.h>
using namespace std;

#define hash idyhash

const int S = 114281;
struct Hash {
	int head[S], dest[S][2], last[S], etot;
	void init() {
		memset(head, 0, sizeof(head));
		etot = 0;
	}
	void add(int a, int b) {
		int key = a % S;
		for(int t = head[key]; t; t = last[t])
			if(dest[t][0] == a) return;
		etot++;
		last[etot] = head[key];
		dest[etot][0] = a;
		dest[etot][1] = b;
		head[key] = etot;
	}
	int query(int a) {
		int key = a % S;
		for(int t = head[key]; t; t = last[t])
			if(dest[t][0] == a) return dest[t][1];
		return -1;
	}
}hash;

int a, b, p;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int mpow(int a, int b, int mod) {
	int rt;
	for(rt = 1; b; b>>=1, a = (1LL*a*a)%mod)
		if(b & 1) rt = (1LL*rt*a)%mod;
	return rt;
}
void exgcd(int a, int b, int &d, int &x, int &y) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		int xx, yy;
		exgcd(b, a%b, d, xx, yy);
		//	b * xx + (a - (a/b)*b) * yy = d
		//	a * yy + b * (xx - (a/b)*yy) = d
		x = yy;
		y = xx - a / b * yy;
	}
}
int inverse(int a, int p) {
	int d, x, y;
	exgcd(a,p,d,x,y);
	assert(d == 1);
	//	a * x + p * y = 1
	return (x % p + p) % p;
}
int ind(int g, int a, int p) {
	hash.init();
	int b = (int)ceil(sqrt(a)) + 1;
	int cur = 1;
	for(int i = 0; i < b; i++, cur=(1LL*cur*g)%p) {
		if(cur == a) return i;
		hash.add(cur,i);
	}
	int base = inverse(cur,p);
	cur = 1LL * base * a % p;
	for(int i = b; i <= p - 1; i += b,cur=(1LL*cur*base)%p) {
		int j = hash.query(cur);
		if(j != -1) return i + j;
	}
	assert(false);
	return -1;
}
vector<pair<int,int> > factor(int a) {
	vector<pair<int,int> > fac;
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			fac.push_back(make_pair(i,0));
			while(a % i == 0) {
				a /= i;
				fac.back().second++;
			}
		}
	}
	return fac;
}
int findroot(int p) {
	vector<pair<int,int> > fac = factor(p - 1);
	for(int g = 1; ; g++) {
		bool ok = true;
		for(int t = 0; t < (int)fac.size(); t++) {
			int q = fac[t].first;
			if(mpow(g,(p - 1) / q,p) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
	assert(false);
	return -1;
}

int main() {
	int T, type;
	scanf("%d%d", &T, &type);
	while(T--) {
		scanf("%d%d%d", &a, &b, &p);
		int cnt, sum;
		if(b == 0) {
			cnt = 1;
			sum = 0;
		} else {
			int g = findroot(p);
			int indb = ind(g,b,p);
			int ph = p - 1;
			int d = gcd(a,ph);
			if(indb % d != 0) {
				cnt = sum = 0;
			} else {
				//	aa x = bb(cc)
				int aa = a;
				int bb = indb;
				int cc = ph;
				aa /= d, bb /= d, cc /= d;
				bb = 1LL * bb * inverse(aa,cc) % cc;
				cnt = ph / cc;
				int q = mpow(g,cc,p);
				if(q == 1) {
					sum = 1LL * d * mpow(g,bb,p) % p;
				} else {
					sum = 0;
				}
				//	g^bb,g^(bb+cc),...,g^(bb+ph-cc)
				//	g^bb(1 - g^(cc * ph/cc)) / (1 - g^cc)
			}
		}
		if(type == 0)
			printf("%d\n", cnt);
		else
			printf("%d %d\n", cnt, sum);
	}
}

