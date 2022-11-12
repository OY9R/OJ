#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		int sum=0;
		vector<pair<int,int>> b;
		int packnum=n;
		for(int i=0;i<n;i++)
			b.push_back({i,i});
		for(int i=0;i<n;i++)
			sum+=a[i];
		if(sum!=0&&sum%2==1){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<n&&sum>0;i++){
			if(a[i]==1){
				b[i-1]={b[i-1].first,b[i].second};
				b[i]={-1,-1};
				sum-=2;
				i++,packnum--;
			}
		}
		for(int i=1;i<n&&sum<0;i++){
			if(a[i]==-1){
				b[i-1]={b[i-1].first,b[i].second};
				b[i]={-1,-1};
				sum+=2;
				i++,packnum--;
			}
		}
		if(sum==0){
			cout<<packnum<<endl;
			for(int i=0;i<n;i++){
				if(b[i].first!=-1){
					cout<<b[i].first+1<<' '<<b[i].second+1<<endl;
				}
			}
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}