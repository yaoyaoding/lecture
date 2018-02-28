#include <cstdio>

const int N = 100000 + 10;

int n, q;
int aa[N];
long long bit[N];

void modify(int r, int delta) {
	for(int i = r; i; i -= i & -i)
		bit[i] += delta;
}
void modify(int l, int r, int delta) {
	modify(r, delta);
	if(l >= 1) modify(l-1, -delta);
}
int query(int pos) {
	long long rt = 0;
	for(int i = pos; i <= n; i += i & -i)
		rt += bit[i];
	return (int)rt;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", aa+i);
		modify(i, i, aa[i]);
	}
	scanf("%d", &q);
	while(q--) {
		char ch[100];
		scanf("%s", ch);
		if(ch[0] == 'q') {
			int pos;
			scanf("%d", &pos);
			printf("%d\n", query(pos));
		} else {
			int l, r, delta;
			scanf("%d%d%d", &l, &r, &delta);
			modify(l, r, delta);
		}
	}
}
