#include<bits/stdc++.h>
using namespace std;
const int N=2023;
int c[N][N],s[N][N];
int main(){
    int t,k;cin>>t>>k;
    c[0][0]=1;
    for(int i=1;i<N;i++){
        c[i][0]=1;
        for(int j=1;j<N;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(j<=i&&!c[i][j])s[i][j]++;
        }
    }
    for(int n,m;t--;cout<<s[n][m]<<'\n')cin>>n>>m;
}