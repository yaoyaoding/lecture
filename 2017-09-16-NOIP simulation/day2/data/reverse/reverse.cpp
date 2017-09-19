#include <bits/stdc++.h>
using namespace std;

typedef vector<char> String;

void back(String &a) {
	if(a.back() == 'A') {
		a.pop_back();
	} else {
		a.pop_back();
		reverse(a.begin(), a.end());
	}
}
String solve(String a, String b) {
	while(a.size() > b.size()) back(a);
	while(b.size() > a.size()) back(b);
	while(a != b) back(a), back(b);
	return a;
}
void read(String &a) {
	string aa;
	cin >> aa;
	a.clear();
	for(int i = 0; i < (int)aa.size(); i++)
		a.push_back(aa[i]);
}
void print(const String &a) {
	if(a.empty())
		cout << "-1" << endl;
	else {
		string aa;
		for(int i = 0; i < (int)a.size(); i++)
			aa.push_back(a[i]);
		cout << aa << endl;
	}
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		String a, b;
		read(a);
		read(b);
		print(solve(a,b));
	}
}
