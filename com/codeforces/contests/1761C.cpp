#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > a(n+1);
		for(int i=1;i<=n;i++){
			a[i].push_back(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char t;cin>>t;
				if(t=='1'){
					a[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i].size()<<' ';
			for(int j=0;j<a[i].size();j++){
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}