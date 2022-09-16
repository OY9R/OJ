#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int m[N];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>m[i];
	sort(m,m+n);
	cout<<m[n/2]<<endl;
	return 0;
}