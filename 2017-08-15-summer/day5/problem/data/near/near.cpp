#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
const long long ool = 0x3f3f3f3f3f3f3f3fll;

inline long long Abs(long long x) {
	return x < 0 ? -x : x;
}
struct Vector {
	int i;
	long long x, y;
	Vector(){}
	Vector(int i, long long x, long long y):i(i),x(x),y(y){}
	long long slen() {
		return x * x + y * y;
	}
};
typedef Vector Point;
Vector operator+(const Vector &r, const Vector &s) {
	return Vector(0, r.x + s.x, r.y + s.y);
}
Vector operator-(const Vector &r, const Vector &s) {
	return Vector(0, r.x - s.x, r.y - s.y);
}
long long cross(const Vector &r, const Vector &s) {
	return r.x * s.y - r.y * s.x;
}
long long dot(const Vector &r, const Vector &s) {
	return r.x * s.x + r.y * s.y;
}
struct Box {
	long long xmin, xmax, ymin, ymax;
	void init() {
		xmin = ymin = ool;
		xmax = ymax = -ool;
	}
	void add(const Point &p) {
		xmin = min(xmin, p.x);
		xmax = max(xmax, p.x);
		ymin = min(ymin, p.y);
		ymax = max(ymax, p.y);
	}
	long long sdis(const Point &p) {
		long long dx, dy;

		if(p.x <= xmin) dx = xmin - p.x;
		else if(p.x <= xmax) dx = 0;
		else dx = p.x - xmax;

		if(p.y <= ymin) dy = ymin - p.y;
		else if(p.y <= ymax) dy = 0;
		else dy = p.y - ymax;

		return dx * dx + dy * dy;
	}
};
struct Cmp {
	int type;	//	0 for x, 1 for y
	Cmp(){}
	Cmp(int type):type(type){}
	bool operator()(const Point &r, const Point &s) {
		if(type == 0) 
			return r.x < s.x || (r.x == s.x && r.y < s.y);
		else
			return r.y < s.y || (r.y == s.y && r.x < s.x);
	}
};
struct Node {
	Point pt;
	Box box;
	Cmp cmp;
	Node *ls, *rs;
}pool[N], *tail = pool, *root;

int n, np, ni;
Point pts[N], poly[N], inpts[N];
Point qpoint;

struct Pcmp {
	bool operator()(const Point &r, const Point &s) {
		long long dr = (r - qpoint).slen();
		long long ds = (s - qpoint).slen();
		if(dr != ds) return dr < ds;
		return r.i < s.i;
	}
};

priority_queue<Point,vector<Point>,Pcmp> pq;

Node *build(int lf, int rg, int type) {
	if(lf > rg) return 0;
	Node *nd = ++tail;
	int mid = (lf + rg) >> 1;
	nth_element(inpts+lf,inpts+mid,inpts+rg+1,nd->cmp);
	nd->pt = inpts[mid];
	nd->cmp = Cmp(type);
	nd->box.init();
	for(int i = lf; i <= rg; i++) nd->box.add(inpts[i]);
	nd->ls = build(lf, mid - 1, !type);
	nd->rs = build(mid+1, rg, !type);
	return nd;
}
bool onseg(const Point &p, const Point &A, const Point &B) {
	return cross(p - A, B - A) == 0 && dot(p - A, p - B) <= 0;
}
inline int sign(long long x) {
	if(x == 0) return 0;
	if(x > 0) return 1;
	else return -1;
}
bool inpoly(const Point &p, int np, Point poly[N]) {
	int num = 0;
	for(int i = 1; i <= np; i++) {
		int ni = (i == np ? 1 : i + 1);
		if(onseg(p,poly[i],poly[ni])) return true;
		int k = sign(cross(poly[ni] - poly[i], p - poly[i]));
		int d1 = sign(poly[i].y - p.y);
		int d2 = sign(poly[ni].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0) num++;
		if(k < 0 && d2 <= 0 && d1 > 0) num--;
	}
	return num != 0;
}
void query(Node *nd) {
	if(nd == 0) return;
	if(pq.size() >= 2 && (nd->box.sdis(qpoint) > (qpoint - pq.top()).slen())) return;
	pq.push(nd->pt);
	while(pq.size() > 2) pq.pop();
	if(nd->cmp(qpoint, nd->pt)) {
		query(nd->ls);
		query(nd->rs);
	} else {
		query(nd->rs);
		query(nd->ls);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			long long x, y;
			scanf("%lld%lld", &x, &y);
			pts[i] = Point(i,x,y);
		}
		int R;
		scanf("%d", &R);
		for(int r = 1; r <= R; r++) {
			scanf("%d", &np);
			for(int i = 1; i <= np; i++) {
				long long x, y;
				scanf("%lld%lld", &x, &y);
				poly[i] = Point(i,x,y);
			}
			ni = 0;
			for(int i = 1; i <= n; i++) {
				if(inpoly(pts[i],np,poly)) 
					inpts[++ni] = pts[i];
			}
			tail = pool;
			root = build(1,ni,0);
			int q;
			scanf("%d", &q);
			while(q--) {
				long long x, y;
				scanf("%lld%lld", &x, &y);
				qpoint = Point(0,x,y);
				while(!pq.empty()) pq.pop();
				query(root);
				int ans[2];
				ans[0] = pq.top().i; pq.pop();
				ans[1] = pq.top().i; pq.pop();
				printf("%d %d\n", ans[1], ans[0]);
			}
		}
	}
}

