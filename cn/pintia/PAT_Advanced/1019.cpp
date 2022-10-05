#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main() {
	int n, b, cnt = 0;
	bool flag = 1;
	cin >> n >> b;
	string s = "";
	if(n == 0) {
		cout << "Yes" << endl;
		cout << 0;
		return 0;
	}
	while(n) {
		a[cnt++] = n % b;
		n /= b;
	}
	for(int i = 0; i < cnt / 2; i++) {
		if(a[i] != a[cnt - 1 - i]) {
			flag = 0;
			break;
		}
	}
	if(flag)
		cout << "Yes" << endl; else
		cout << "No" << endl;
	for(int i = cnt - 1; i >= 0; i--) {
		cout << a[i];
		if(i)
			cout << ' ';
	}
	return 0;
}