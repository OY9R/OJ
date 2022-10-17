#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k=1;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			int add=0;
			while(k<=n&&a[i-1]>a[i]+add){
				add+=k++;
				cout<<i+1<<' ';
			}
			if(k>n)break;
		}
		while(k<=n){
			cout<<"1 ";
			k++;
		}
		cout<<endl;
	}
	return 0;
}