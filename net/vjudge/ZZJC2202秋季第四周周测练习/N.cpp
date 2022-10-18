#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,m,s[N][N],l[N],r[N],h[N],k[N],top;
ll ans;
char p;
void ddzl(){
    top=0;
    for(int i=m;i>=1;i--){
        while (top!=0&&h[i]<=h[k[top]])l[k[top]]=i,top--;
        k[++top]=i;
    }
    while(top)l[k[top]]=0,top--;
}
void ddzr(){
    top=0;
    for(int i=1;i<=m;i++){
        while(top!=0&&h[i]<h[k[top]])r[k[top]]=i,top--;
        k[++top]=i;
    }
    while(top)r[k[top]]=m+1,top--;
}
void solve(){
    ddzl();
    ddzr();
    for(int j=1;j<=m;j++)
    ans+=1ll*h[j]*(j-l[j])*(r[j]-j);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        s[x][y]=1;
    }
    m=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(!s[i][j])h[j]++;
            else h[j]=0;
        solve();
    }
    cout<<ans<<endl;
    return 0;
}