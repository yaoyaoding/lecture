#include <bits/stdc++.h>
using namespace std;

struct Range {
	int l, r;
	Range(){}
	Range(int l, int r):l(l),r(r){}
};
bool operator<(const Range &r, const Range &s) {
	return r.r < s.r;
}


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
		}
		vector<Range> ranges;
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(u > v) swap(u,v);
			ranges.push_back(Range(u,v));
		}
		sort(ranges.begin(),ranges.end());
		int last = -1;
		int ans = 0;
		for(int i = 0; i < (int)ranges.size(); i++) {
			if(ranges[i].l <= last) continue;
			last = ranges[i].r;
			ans++;
		}
		printf("%d\n", ans);
	}
}

