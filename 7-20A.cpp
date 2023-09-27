#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,b,g,x,y;cin>>n>>m>>b>>g;
    int nn=n,mm=m;
    vector<bool> X(n+1),Y(m+1);
    while(b--){
        cin>>x>>y;
        for(int i=x;i<=y;i++)
            if(!X[i])X[i]=true,nn--;
    }
    while(g--){
        cin>>x>>y;
        for(int i=x;i<=y;i++)
            if(!Y[i])Y[i]=true,mm--;
    }
    cout<<n*m-nn*mm<<'\n';
}