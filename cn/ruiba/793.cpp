#include<bits/stdc++.h>
using namespace std;
vector<int> p;
bool v[20000000];
void getprime(int n){
	for(int i=2;i<=n;i++){
		if(!v[i])p.push_back(i);
		for(int j=0;i*p[j]<=n;j++){
			v[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	int n;
	cin>>n;
	getprime(n);
	for(int i=0;p[i]<=n&&i<p.size();i++){
		int ans=0;
		for(int k=n;k;k/=p[i])
			ans+=k/p[i];
		cout<<p[i]<<' '<<ans<<'\n';
	}
	return 0;
}