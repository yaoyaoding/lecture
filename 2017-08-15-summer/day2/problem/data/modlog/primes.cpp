#include <bits/stdc++.h>
using namespace std;

bool isprime(int a) {
	for(int i = 2; i * i <= a; i++)
		if(a % i == 0) return false;
	return true;
}
int main() {
	int L, R;
	scanf("%d%d", &L, &R);
	bool found = false;
	for(int i = L; i <= R; i++)
		if(isprime(i)) {
			printf("%c%d", found ? ' ' : 0, i);
			found = true;
		}
}

