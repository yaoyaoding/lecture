#include <cstdio>

const int N = 100000 + 10;
const int Mod = 1e9 + 7;

struct Node;
void modify(Node *nd, int lf, int rg, int L, int R, long long A, long long B);
struct Node {
	long long sum, a, b;
	Node *ls, *rs;
	void update() {
		sum = ls->sum + rs->sum;
		if(sum >= Mod) sum -= Mod;
	}
	void pushdown(int lf, int rg) {
		if(a == 1 && b == 0) return;
		int mid = (lf + rg) >> 1;
		modify(ls, lf, mid, lf, mid, a, b);
		modify(rs, mid+1, rg, mid+1, rg, a, b);
		a = 1, b = 0;
	}
}pool[N*2], *tail=pool, *root;

int n, q;
int aa[N];

Node *build(int lf, int rg) {
	Node *nd = ++tail;
	if(lf == rg) {
		nd->sum = aa[lf];
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build(lf, mid);
		nd->rs = build(mid+1, rg);
		nd->a = 1;
		nd->b = 0;
		nd->update();
	}
	return nd;
}
void modify(Node *nd, int lf, int rg, int L, int R, long long A, long long B) {
	if(L <= lf && rg <= R) {
		nd->sum = (nd->sum * A + B * (rg - lf + 1)) % Mod;
		nd->a = nd->a * A % Mod;
		nd->b = (nd->b * A + B) % Mod;
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf, rg);
	if(L <= mid) modify(nd->ls, lf, mid, L, R, A, B);
	if(R > mid) modify(nd->rs, mid+1, rg, L, R, A, B);
	nd->update();
}
long long query(Node *nd, int lf, int rg, int L, int R) {
	if(L <= lf && rg <= R) {
		if(nd->sum >= Mod) {
			fprintf(stderr,"Strange\n");
		}
		return nd->sum;
	}
	int mid = (lf + rg) >> 1;
	long long rt = 0;
	nd->pushdown(lf, rg);
	if(L <= mid) rt += query(nd->ls, lf, mid, L, R);
	if(R > mid) rt += query(nd->rs, mid+1, rg, L, R);
	if(rt >= Mod) rt -= Mod;
	return rt;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", aa + i);
	root = build(1,n);
	scanf("%d", &q);
	while(q--) {
		char ch[10];
		scanf("%s", ch);
		if(ch[0] == 'm') {
			int l, r, A, B;
			scanf("%d%d%d%d", &l, &r, &A, &B);
			modify(root, 1, n, l, r, A, B);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", (int)query(root, 1, n, l, r));
		}
	}
}
