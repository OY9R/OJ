#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,i=1,ans=0;
    cin>>m>>n;
    while(m/i||n/i){
        ans+=(m/i%10+n/i%10)*i;
        if(ans/i%10>1){
            ans+=10*i-2*i;
        }
        i*=10;
    }
    cout<<ans;
    return 0;
}