#include <bits/stdc++.h>
using namespace std;

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
	return Vector(r.x * s, r.y * s);
}
Vector operator/(const Vector &r, double s) {
	return Vector(r.x / s, r.y / s);
}
double cross(const Vector &r, const Vector &s) {
	return r.x * s.y - s.x * r.y;
}
double dot(const Vector &r, const Vector &s) {
	return r.x * s.x + r.y * s.y;
}

int n;
vector<Point> pts, cvx;

double area(const Point &a, const Point &b, const Point &c) {
	return fabs(cross(b - a, c - a)) / 2.0;
}
bool onleft(const Point &a, const Point &b, const Point &p) {
	return cross(b - a, p - a) > 0;
}
vector<Point> convex(vector<Point> pts) {
	int n = (int)pts.size();
	sort(pts.begin(), pts.end());
	vector<Point> stk;
	int m = 0;
	for(int i = 0; i < n; i++) {
		while(m > 1 && !onleft(stk[m-2], stk[m-1], pts[i])) {
			m--;
			stk.pop_back();
		}
		m++;
		stk.push_back(pts[i]);
	}
	int k = m;
	for(int i = n - 2; i >= 0; i--) {
		while(m > k && !onleft(stk[m-2], stk[m-1], pts[i])) {
			m--;
			stk.pop_back();
		}
		m++;
		stk.push_back(pts[i]);
	}
	if(n > 1) {
		m--;
		stk.pop_back();
	}
	return stk;
}

double maxarea(vector<Point> cvx) {
	int n = (int)cvx.size();
	vector<int> next(n, 0);
	for(int i = 0; i < n; i++)
		next[i] = (i + 1) % n;
	if(n <= 2) return 0.0;
	if(n == 3) return area(cvx[0], cvx[1], cvx[2]);
	double ans = 0.0;
	for(int i = 0; i < n; i++) 
		for(int j = next[next[i]], a = next[i], b = next[j]; next[j] != i; j = next[j]) {
			while(area(cvx[i],cvx[a],cvx[j]) < area(cvx[i],cvx[next[a]],cvx[j])) a = next[a];
			while(area(cvx[j],cvx[b],cvx[i]) < area(cvx[j],cvx[next[b]],cvx[i])) b = next[b];
			ans = max(ans, area(cvx[i],cvx[a],cvx[j]) + area(cvx[j],cvx[b],cvx[i]));
		}
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<Point> pts;
	for(int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		pts.push_back(Point(x,y));
	}
	printf("%.3f\n", maxarea(convex(pts)));
}

