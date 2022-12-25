#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int f[1000100];
int n,m;
int find(int x){
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
int main() {
    while(cin>>n&&n){
        int ans=0;
        cin>>m;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            f[find(a)]=find(b);
        }
        for(int i=1;i<=n;i++)
            if(find(i)==i)ans++;
        cout<<ans-1<<endl;
    }
    return 0;
}