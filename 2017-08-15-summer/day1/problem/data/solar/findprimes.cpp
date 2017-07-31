#include <bits/stdc++.h>
using namespace std;

bool isprime(int a) {
	for(int i = 2; i * i <= a; i++)
		if(a % i == 0) return false;
	return true;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	while(b--) {
		while(!isprime(a)) a++;
		printf("%d\n", a++);
	}
}

