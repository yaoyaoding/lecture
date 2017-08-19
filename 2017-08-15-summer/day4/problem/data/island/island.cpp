#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
const double eps = 1e-7;

int sign(double x) {
	return (x > -eps) - (x < eps);
}

struct Vector {
	double x, y;
	Vector(){}
	Vector(double x, double y):x(x),y(y){}
	double ang() const {
		return atan2(y,x);
	}
	double len() const {
		return sqrt(x * x + y * y);
	}
};
typedef Vector Point;
bool operator<(const Vector &r, const Vector &s) {
	return r.x < s.x || (r.x == s.x && r.y < s.y);
}
Vector operator+(const Vector &r, const Vector &s) {
	    return Vector(r.x + s.x, r.y + s.y);
}
Vector operator-(const Vector &r, const Vector &s) {
	    return Vector(r.x - s.x, r.y - s.y);
}
Vector operator*(const Vector &r, double s) {
	    return Vector(r.x * s, r.y *s);
}
Vector operator/(const Vector &r, double s) {
	    return Vector(r.x / s, r.y / s);
}
double cross(const Vector &r, const Vector &s) {
	return r.x * s.y - r.y * s.x;
}
double dot(const Vector &r, const Vector &s) {
	return r.x * s.x + r.y * s.y;
}
Vector normal(const Vector &u) {
	return Vector(-u.y,u.x);
}
Vector zoom(const Vector &u, double s) {
	return u * (s / u.len());
}
struct Line {
	Point p;
	Vector u;
	double ang;
	Line(){}
	Line(Point p, Vector u):p(p),u(u),ang(u.ang()){}
};
bool operator<(const Line &r, const Line &s) {
	return r.ang < s.ang;
}
bool operator ==(const Line &r, const Line &s) {
	return sign(r.ang - s.ang) == 0;
}

int n;
vector<Point> cvx;
vector<Line> lines;

bool onleft(const Point &a, const Point &b, const Point &p) {
	return cross(b - a,p - a) > 0;
}
bool onleft(const Line &l, const Point &p) {
	return cross(l.u,p-l.p) > 0;
}
Point line_intersect(Point P, Vector u, Point Q, Vector v) {
	Vector w = P - Q;
	double t = cross(v,w) / cross(u,v);
	return P + u * t;
}
Point line_intersect(const Line &a, const Line &b) {
	return line_intersect(a.p,a.u,b.p,b.u);
}
int half_plane_intersect(vector<Line> &h) {
	sort(h.begin(),h.end());

	int n = (int)h.size();
	int first, last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first = last = 0] = h[0];
	for(int i = 1; i < n; i++) {
		while(first < last && !onleft(h[i],p[last-1])) last--;
		while(first < last && !onleft(h[i],p[first])) first++;
		q[++last] = h[i];
		if(fabs(cross(q[last].u,q[last-1].u)) < eps) {
			last--;
			if(onleft(q[last],h[i].p)) q[last] = h[i];
		}
		if(first < last) p[last-1] = line_intersect(q[last-1],q[last]);
	}
	while(first < last && !onleft(q[first],p[last-1])) last--;
	if(last - first <= 1) return 0;
	p[last] = line_intersect(q[last], q[first]);
	return last - first + 1;
}
bool check(double mid) {
	vector<Line> h;
	for(int i = 0; i < n; i++) {
		Point a = cvx[i];
		Point b = cvx[(i+1)%n];
		Vector u = zoom(normal(b - a), mid);
		h.push_back(Line(a + u, b - a));
	}
	return half_plane_intersect(h);
}
int main() {
	while(scanf("%d", &n) == 1 && n) {
		cvx.clear();
		for(int i = 1; i <= n; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			cvx.push_back(Point(x,y));
		}
		double lf = 0.0, rg = 20000.0;
		for(int i = 0; i < 100; i++) {
			double mid = (lf + rg) / 2.0;
			if(check(mid))
				lf = mid;
			else
				rg = mid;
		}
		printf("%.2f\n", (lf + rg) / 2.0);
	}
}

