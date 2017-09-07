#include <bits/stdc++.h>
using namespace std;

int a;

int ceil(int a, int b);
int floor(int a, int b) {
	if(a >= 0)
		return a / b;
	else
		return -ceil(-a, b);
}
int ceil(int a, int b) {
	if(a >= 0)
		return (a + b - 1) / b;
	else
		return -floor(-a, b);
}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) == 2)
		printf("floor(a/b) = %d ceil(a/b) = %d a/b = %d  a %% b = %d  [%s]\n", floor(a,b), ceil(a,b), a / b, a % b, (a/b)*b + a%b == a ? "YES" : "NO");
}

