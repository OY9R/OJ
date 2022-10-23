#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> m(n);
		for(int i=0;i<n;i++)
			cin>>m[i].first;
		for(int i=0;i<n;i++)
			cin>>m[i].second;
		int maxi=0;
		for(int i=1;i<n;i++)
			if(m[maxi].second<m[i].second)
				maxi=i;
		long long sum=0;
		for(int i=0;i<maxi;i++){
			sum+=m[i].first+m[i].second;
		}
		for(int i=n-1;i>maxi;i--){
			sum+=m[i].first+m[i].second;
		}
		cout<<sum+m[maxi].first<<endl;
	}
	return 0;
}