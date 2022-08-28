#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll k[7];
int m[2][5]={0,7,6,5,0,0,5,3,1,0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,s;
	cin>>t;
	while(t--){
		cin>>s;
		for(int i=1;i<=6;i++)
			cin>>k[i];
		int need=0;
		for(int i=4;i<=6;i++)
			need+=k[i];
		k[1]-=k[5]*11;
		k[2]-=k[4]*5;
		need+=(k[3]+3)/4;
		k[1]-=m[0][k[3]%4];
		k[2]-=m[1][k[3]%4];
		if(k[2]>0){
			need+=(k[2]+8)/9;
			k[2]=k[2]%9==0?0:9-k[2]%9;
		}
		k[1]+=k[2]*4;
		if(k[1]>0)
			need+=(k[1]+35)/36;
		//cout<<need<<endl;
		if(need>s) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
