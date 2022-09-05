#include<bits/stdc++.h>
using namespace std;
int main(){
    int w=0,n,ans=0;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a>w)ans+=(a-w)*6;
        else ans+=(w-a)*4;
        ans+=5;
        w=a;
    }
    cout<<ans;
    return 0;
}