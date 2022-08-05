#include "bits/stdc++.h"
using namespace std;
int m[21],sum,ans,n;
void dfs(int l,int a){
    if(a==sum/4) ans++;
    if(ans>=4){
        cout<<"yes";
        exit(0);
    }
    if(a>=sum/4) return;
    for(int i=l;i<=n;i++)
        dfs(l+1,a+m[i]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m[i];
        sum+=m[i];
    }
    if(sum%4!=0){
        cout<<"no";
        return 0;
    }
    dfs(1,0);
    cout<<(ans>=4?"yes":"no");
    return 0;
}
