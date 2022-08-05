#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int m[21];
int mm[21];
bool isPrime(int n){
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return false;
    return true;
}
void dfs(int l){
    if(l==n){
        if(isPrime(m[n]+1)){
            for(int i=1;i<=n;i++)
                cout<<m[i]<<' ';
            cout<<endl;
        }
        return;
    }
    for(int i=2;i<=n;i++){
        if(mm[i]&&isPrime(m[l]+i)){
            mm[i]=false;
            m[l+1]=i;
            dfs(l+1);
            mm[i]=true;
        }
    }
}
signed main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        mm[i]=true;
    }
    m[1]=1;
    dfs(1);
    return 0;
}
