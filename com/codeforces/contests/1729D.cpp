#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int m[N];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>m[i];
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			m[i]=tmp-m[i];
		}
		sort(m,m+n);
		int l=0,r=n-1,cnt=0;
		while(l<r){
			if(m[l]+m[r]<0)l++;
			else{
				cnt++;
				l++;
				r--;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
