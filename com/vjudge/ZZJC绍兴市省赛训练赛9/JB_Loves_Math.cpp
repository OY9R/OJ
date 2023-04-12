#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,ans=0;
    cin>>a>>b;
    if(a==b) ans=0;
    else if(a<b){
        if((b-a)&1)ans=1;
        else if((b-a)%4)ans=2;
        else ans=3;
    }else{
        if((a-b)&1)ans=2;
        else ans=1;
    }
    cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}