#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		set<int> st;
		int a, m;
		scanf("%d%d", &a, &m);
		for(int cur = a % m; !st.count(cur); cur = 1LL * cur * a % m) {
			st.insert(cur);
		}
		printf("%d\n", (int)st.size());
	}
}

