#include<bits/stdc++.h>
using namespace std;
const int N=100100;
const double eps=1e-8;
int a[N],t[N];
void solve() {
	int n;
	cin >> n;
	vector<int> x(n), t(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];
	vector<int> a;
	for(int i = 0; i < n; i++) {
		a.push_back(x[i] + t[i]);
		a.push_back(x[i] - t[i]);
	}
	int mn = a[0], mx = a[0];
	for(int val : a) {
		mn = min(mn, val);
		mx = max(mx, val);
	}
	int sum = mn + mx;
	cout << sum / 2;
	if(sum % 2 != 0)
		cout << ".5";
	cout << '\n';
}
int main() {
	int _;
	cin>>_;
	while(_--)
		solve();
	return 0;
}