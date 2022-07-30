#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 200000
int n, m, ans;
int c[maxn];
int a[maxn];
int b[maxn];
int d[maxn];

bool cmp1(int x, int y) {
	return a[x] < a[y];
}
bool cmp2(int x, int y) {
	return d[x] > d[y];
}

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> c[i] >> a[i];
	}
	
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		sum += b[i];
		d[i] = i;
	}
	
	sort(c + 1, c + m + 1, cmp1);
	sort(d + 1, d + n + 1, cmp2);
	sum += a[c[1]];
	sum -= b[d[1]];
	cout << sum << endl;
}
