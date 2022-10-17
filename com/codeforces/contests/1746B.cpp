#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m=0;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		int l=0,r=n-1;
		while(l<r){
			while(l<r&&a[l]==0)l++;
			while(l<r&&a[r]==1)r--;
			if(l<r){
				m++;
				l++;
				r--;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}