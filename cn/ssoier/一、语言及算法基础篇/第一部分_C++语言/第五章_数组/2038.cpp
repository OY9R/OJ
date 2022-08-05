#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a[1005], mxi = 1;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		if(a[i] > a[mxi])
			mxi = i;
	cout << mxi;
	return 0;
}