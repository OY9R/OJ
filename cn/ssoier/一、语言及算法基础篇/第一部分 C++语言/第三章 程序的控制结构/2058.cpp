#include "bits/stdc++.h"
using namespace std;
#define ll long long
double n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	cin >> n >> m >> c;
	switch (c) {
		case '-':
			m = -m;
		case '+':
			a = n + m;
			break;
		case '*':
			a = n * m;
			break;
		case '/':
			if (!m) {
				cout << "Divided by zero!";
				return 0;
			}
			a = n / m;
			break;
		default:
			cout << "Invalid operator!";
			return 0;
	}
	//printf("%.1lf", a);
	cout << a;
	return 0;
}
