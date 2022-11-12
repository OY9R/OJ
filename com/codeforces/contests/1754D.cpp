#include<bits/stdc++.h>
using namespace std;
int main(){
		int n,x;
		cin>>n>>x;
		vector<int> a(x+1);
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			a[tmp]++;
		}
		for(int i=2;i<=x;i++){
			a[i]+=a[i-1]/i;
			a[i-1]%=i;
		}
		bool flag=true;
		for(int i=1;i<x;i++){
			if(a[i]!=0){
				flag=false;
				break;
			}
		}
		if(flag&&a[x]>0)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	return 0;
}