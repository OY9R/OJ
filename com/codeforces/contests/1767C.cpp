#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	int n;
	cin>>n;
    vector<int> f(n,2),g(n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int in;cin>>in;
            if(j==i&&in!=1){
                cout<<0;return 0;
            }
            if(in==1){
                for(int k=i+1;k<=j;k++)
                    f[k]=1;
            }
            if(in==2){
                g[j]=-2;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<f[i]<<' ';
    // }
	// cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<g[i]<<' ';
    // }
    // cout<<endl;
    long long ans=1;
    bool flag=true;
    for(int i=0;i<n;i++){
        ans*=f[i];
        if(flag&&g[i]){
            ans-=2;
            flag=false;
        }
        ans%=mod;
    }
    cout<<ans;
	return 0;
}