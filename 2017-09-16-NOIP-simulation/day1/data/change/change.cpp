#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, a, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &a, &b);
		if(b * 2 == a)
			printf("1\n");
		else {
			if(b == 1 || b == 10 || b == 100 || b == 1000)
				printf("2\n");
			else
				printf("1\n");
		}
	}
}

