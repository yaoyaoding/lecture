#include <bits/stdc++.h>
using namespace std;

int mpow(int a, int b, int m) {
	int rt;
	for(rt = 1; b; b>>=1,a=(1LL*a*a)%m)
		if(b & 1) rt=(1LL*rt*a)%m;
	return rt;
}

int main() {
	int T, type;
	scanf("%d%d", &T, &type);
	while(T--) {
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		int cnt = 0, sum = 0;
		for(int x = 0; x < p; x++) {
			if(mpow(x,a,p) == b) {
				cnt++;
				sum = (sum + x) % p;
			}
		}
		if(type == 0)
			printf("%d\n", cnt);
		else
			printf("%d %d\n", cnt, sum);
	}
}

