#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,opt,x,y,ans;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>opt;
		if(opt==1){
			cin>>x>>y;
			for(int j=x;j<N;j+=(j&-j))a[j]++;
			for(int j=y+1;j<N;j+=(j&-j))a[j]--;
		}else{
			cin>>x;ans=0;
			for(int j=x;j;j-=(j&-j))ans+=a[j];
			cout<<ans%2<<'\n';
		}
	}
}