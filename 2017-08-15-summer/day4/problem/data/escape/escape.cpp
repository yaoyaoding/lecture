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

int n, q;
vector<Point> poly;

bool point_on_line(const Point &p, const Point &A, const Point &B) {
	return sign(cross(B-A, p-A)) == 0 && sign(dot(A-p,B-p)) <= 0;
}
bool in_polygon(const Point &p, const vector<Point> &poly) {
	int n = (int)poly.size();
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		Point a = poly[i], b = poly[(i + 1) % n];
		if (point_on_line(p, a, b)) return true; // bounded included
		int x = sign(cross(p - a, b - a));
		int y = sign(a.y - p.y);
		int z = sign(b.y - p.y);
		if (x > 0 && y <= 0 && z > 0) counter++;
		if (x < 0 && z <= 0 && y > 0) counter--;
	}
	return counter != 0;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		poly.push_back(Point(x,y));
	}
	while(q--) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		if(in_polygon(Point(x,y), poly))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

