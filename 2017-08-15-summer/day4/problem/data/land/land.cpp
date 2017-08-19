#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
const double eps = 1e-8;

int sign(double x) {
	return (x > -eps) - (x < eps);
}

struct Vector {
	double x, y;
	Vector(){}
	Vector(double x, double y):x(x),y(y){}
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

int n;
Point aa[N][2];
vector<Point> pts, cvx;

Vector Line(Point A, Point B) {
	return B - A;
}
bool seg_intersect(Point A, Point B, Point C, Point D) {
	double c1 = cross(Line(A,B),Line(A,C)), c2 = cross(Line(A,B),Line(A,D));
	double c3 = cross(Line(C,D),Line(C,A)), c4 = cross(Line(C,D),Line(C,B));
	return sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0;
}
Point line_intersect(Point P, Vector u, Point Q, Vector v) {
	double t = cross(Line(P,Q), v) / cross(u, v);
	return P + u * t;
}
bool onleft(Point A, Point B, Point C) {
	return cross(Line(A,B),Line(A,C)) > 0;
}
vector<Point> convex(vector<Point> pts) {
	int n = (int)pts.size();
	int m = 0;
	vector<Point> cvx;
	sort(pts.begin(), pts.end());
	for(int i = 0; i < n; i++) {
		while(m > 1 && onleft(cvx[m - 2], cvx[m - 1], pts[i])) {
			cvx.pop_back();
			m--;
		}
		cvx.push_back(pts[i]);
		m++;
	}
	int k = m;
	for(int i = n - 2; i >= 0; i--) {
		while(m > k && onleft(cvx[m - 2], cvx[m - 1], pts[i])) {
			cvx.pop_back();
			m--;
		}
		cvx.push_back(pts[i]);
		m++;
	}
	if(n > 1) {
		m--;
		cvx.pop_back();
	}
	return cvx;
}
double area(const vector<Point> &poly) {
	double rt = 0.0;
	int n = (int)poly.size();
	for(int i = 0; i < n; i++) {
		rt += cross(poly[i], poly[(i+1)%n]);
	}
	return fabs(rt / 2.0);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%lf%lf%lf%lf", &aa[i][0].x, &aa[i][0].y, &aa[i][1].x, &aa[i][1].y);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			if(seg_intersect(aa[i][0],aa[i][1],aa[j][0],aa[j][1])) {
				pts.push_back(line_intersect(aa[i][0],aa[i][1] - aa[i][0], aa[j][0], aa[j][1] - aa[j][0]));
			}
		}
	double ans = area(convex(pts));
	printf("%.2f\n", ans);
}

