#include <iostream>
#include <algorithm>
using namespace std;

long long gcd( long long a, long long b ) {
	return b == 0 ? abs(a) : gcd( b, a % b );
}
int main() {
	long long a, b;
	while( cin >> a >> b ) {
		cout << gcd( a, b ) << endl;
	}
}

