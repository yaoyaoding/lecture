#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long inf = 1e18;
const int N = 105;
int n, X, Y, Z, a[N];
int m[N], x[N], y[N], z[N], vx[N], vy[N], vz[N];
int tot;
long long mod[N], r[N];

bool cmp(int i, int j) {
	if (m[i] != m[j]) return m[i] > m[j];
	if (x[i] != x[j]) return x[i] < x[j];
	if (y[i] != y[j]) return y[i] < y[j];
	return z[i] < z[j];
}

long long extended_Euclid(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	else {
		long long tmp = extended_Euclid(b, a % b, x, y);
		long long t = x; x = y; y = t - a / b * y;
		return tmp;
	}
}
bool merge(long long &a1, long long &b1, long long &a2, long long &b2) {
	long long x, y;
	long long d = extended_Euclid(a1, a2, x, y);
	long long c = b2 - b1;
	if (c % d) return false;
	long long p = a2 / d;
	x = (c / d * x % p + p) % p;
	b1 += a1 * x;
	a1 *= a2 / d;
	return true;
}
long long China_Remainder(long long a[], long long b[], int n) {
	long long x, y, ans, cir;
	cir = a[1]; ans = b[1];
	for (int i = 2; i <= n; i++)
		if (!merge(cir, ans, a[i], b[i])) return -1;
	return (ans % cir + cir) % cir;
}

bool trans(long long a, long long b, long long p) {
//printf("%d %d %d\n", a, b, p);
	a = (a % p + p) % p;
	b = (b % p + p) % p;
	if (a == 0 && b == 0) return true;
	if (a != 0 && b == 0) return false;
	if (a == 0 && b != 0) {
		long long t = __gcd(b, p); p /= t;
		tot++; mod[tot] = p; r[tot] = 0;
		return true;
	}
	long long t = __gcd(a, __gcd(b, p));
	a /= t; b /= t; p /= t;
	t = __gcd(b, p);
	if (t != 1) return false;
	if (p == 1) return true;
	long long x, y; extended_Euclid(b, p, x, y);
	tot++; mod[tot] = p; r[tot] = a * (x % p + p) % p;
	return true;
}

int calc(int i, int j) {
	tot = 0;
	if (!trans(x[i] - x[j], vx[j] - vx[i], X)
		|| !trans(y[i] - y[j], vy[j] - vy[i], Y)
		|| !trans(z[i] - z[j], vz[j] - vz[i], Z)) return -1;
	/*for (int i = 1; i <= tot; i++)
		printf("%d %d\n", r[i], mod[i]);*/
	return China_Remainder(mod, r, tot);
}

int main() {
	scanf("%d%d%d%d", &n, &X, &Y, &Z);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d%d%d", &m[i], &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
		a[i] = i;
	}
	//int ppp = 0;
	while (1) {
		//if (++ppp == 5) break;
	//puts("..");
		long long t = inf;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++) {
				long long tmp = calc(a[i], a[j]);
				if (tmp > 0) t = min(t, tmp);
			}
		//printf("%I64d\n", t);
		if (t == inf) break;
		for (int i = 1; i <= n; i++) {
			x[a[i]] += t % X * vx[a[i]] % X; x[a[i]] = (x[a[i]] % X + X) % X;
			y[a[i]] += t % Y * vy[a[i]] % Y; y[a[i]] = (y[a[i]] % Y + Y) % Y;
			z[a[i]] += t % Z * vz[a[i]] % Z; z[a[i]] = (z[a[i]] % Z + Z) % Z;
		}
		/*for (int i = 1; i <= 2; i++) {
			printf("%d %d %d %d %d %d\n", x[i], y[i], z[i], vx[i], vy[i], vz[i]);
		}*/
		for (int i = 1; i <= n; i++) {
			int m_sum = m[a[i]], cnt = 1;
			int vx_sum = vx[a[i]], vy_sum = vy[a[i]], vz_sum = vz[a[i]];
			for (int j = i + 1; j <= n; j++)
				if (x[a[i]] == x[a[j]] && y[a[i]] == y[a[j]] & z[a[i]] == z[a[j]]) {
					m_sum += m[a[j]]; cnt++;
					vx_sum += vx[a[j]], vy_sum += vy[a[j]], vz_sum += vz[a[j]];
					swap(a[j], a[n]); j--; n--;
				}
			m[a[i]] = m_sum;
			vx[a[i]] = vx_sum / cnt;
			vy[a[i]] = vy_sum / cnt;
			vz[a[i]] = vz_sum / cnt;
		}
			/*printf("%d\n", n);
			for (int i = 1; i <= n; i++)
		printf("P%d: %d %d %d %d %d %d %d\n", i - 1, m[a[i]], x[a[i]], y[a[i]], z[a[i]], vx[a[i]], vy[a[i]], vz[a[i]]);*/
	}
	
	sort(a + 1, a + n + 1, cmp);
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d %d %d %d %d %d %d\n", m[a[i]], x[a[i]], y[a[i]], z[a[i]], vx[a[i]], vy[a[i]], vz[a[i]]);
	//	printf("P%d: %d %d %d %d %d %d %d\n", i - 1, m[a[i]], x[a[i]], y[a[i]], z[a[i]], vx[a[i]], vy[a[i]], vz[a[i]]);
	return 0;
}
