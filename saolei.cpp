#include<bits/stdc++.h>
using namespace std;
int g[202][202];
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    int ans=0;
    for(int i=(n!=1&&n%3!=1);i<n;i+=3)
        for(int j=(m!=1&&m%3!=1);j<m;j+=3)
            ans+=g[i][j];
    cout<<ans<<'\n';
}