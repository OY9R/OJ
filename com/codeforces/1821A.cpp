#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    int ans=1;
    // if(s[0]=='?')ans*=9;
    bool zero=true;
    for(int i=0;i<s.size();i++){
        if(zero){
            if(s[i]=='0')ans=0;
            else if(s[i]=='?')ans*=9,zero=false;
            else zero=false;
        }else{
            if(s[i]=='?')ans*=10;
        }
    }
    cout<<ans<<endl;
}
int main(){
	int n;cin>>n;
    while(n--)solve();
	return 0;
}