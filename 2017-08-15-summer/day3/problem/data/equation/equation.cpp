#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const double eps = 1e-8;

const int Uniq = 0;
const int ZeroMult = 1;

int n, m;
double aa[N][N];

int gauss() {
	for(int i = 1, j, k; i <= n; i++) {
		j = i;
		for(k = i + 1; k <= m; k++)
			if(fabs(aa[k][i]) > fabs(aa[j][i]))
				j = k;
		for(k = i; k <= n + 1; k++)
			swap(aa[i][k], aa[j][k]);
		if(fabs(aa[i][i]) < eps) return ZeroMult;
		double r = aa[i][i];
		for(k = i; k <= n + 1; k++)
			aa[i][k] /= r;
		for(j = 1; j <= m; j++) {
			if(fabs(aa[j][i]) < eps) continue;
			if(j == i) continue;
			double r = aa[j][i] / aa[i][i];
			for(k = i; k <= n + 1; k++) {
				aa[j][k] -= aa[i][k] * r;
			}
		}
	}
	for(int i = n + 1; i <= m; i++)
		if(fabs(aa[i][n+1]) > eps)
			return ZeroMult;
	return Uniq;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n + 1; j++)
				scanf("%lf", &aa[i][j]);
		int status = gauss();
		if(status == Uniq) {
			for(int i = 1; i <= n; i++)
				printf("%.2f%s", aa[i][n+1], i != n ? " " : "\n");
		} else {
			printf("%s\n", "No solution or more than one solution.");
		}
	}
}

