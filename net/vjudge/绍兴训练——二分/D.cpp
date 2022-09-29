#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n;
int a[N], b[N];
bool check(int x){
	for (int i=1;i<=n;++i)
		b[i] = a[i]>=x;
	int l = n/2, r = n/2+2;
	for ( ;l >= 1 && r <= n; l --, r ++) {
		if (b[l] == b[l+1]) return b[l];
		if (b[r] == b[r-1]) return b[r];
	}
	return b[1];
}

int main(void){
	scanf("%d", &n); 
	n = n*2-1;
	for (int i=1;i<=n;++i)
		scanf("%d", a+i);
	int l = 1, r = n, mid;
	while (l+1 < r) {
		mid = l+r >> 1;
		check(mid) ? l = mid : r = mid;
	}
	cout<<(check(r) ? r : l)<<endl;
	return 0;
}
