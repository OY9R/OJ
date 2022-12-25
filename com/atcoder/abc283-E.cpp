#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int m[1001][1001];
void solve(){
    int X,Y;cin>>X>>Y;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            cin>>m[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<X;i++){
        bool flag1=0,flag2=0;
        for(int j=0;j<Y;j++){
            if((j&&m[i][j-1]==m[i][j])||(j<Y-1&&m[i][j+1]==m[i][j])||(i&&i<X-1&&m[i-1][j]==m[i][j]));
            else{
                if(i==X-1){
                    if(m[i][j]==m[i-1][j])flag1=1;
                    if(m[i][j]!=m[i-1][j])flag2=1;
                }else{
                    if(m[i][j]==m[i+1][j])flag1=1;
                    if(m[i][j]!=m[i+1][j])flag2=1;
                }
            }
        }
        if(flag1&&flag2){
            ans=-1;
            break;
        }
        if(flag2){
            ans++;
            for(int j=0;j<Y;j++)
                m[i][j]=1-m[i][j];
        }
    }
    cout<<min(X-ans,ans);
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}