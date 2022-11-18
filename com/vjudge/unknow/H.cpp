#include<bits/stdc++.h>
using namespace std;
int m[27];
int main() {
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int r=s[0]-'a',l=max(0,r-k);
        k-=r-l;
        int ll=0,rr=0;
        for(int i=1;i<s.size()&&k>0;i++)
            if(r<s[i]-'a'){
                int t=max(0,s[i]-'a'-k);
                if(t<=r){
                    k-=s[i]-'a'-r;
                    r=s[i]-'a';
                }else{
                    ll=t;
                    rr=s[i]-'a';
                    k=0;
                }
            }
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(x<=r&&x>=l)s[i]='a'+l;
            else if(x>=ll&&x<=rr)s[i]='a'+ll;
        }
        cout<<s<<endl;
    }
    return 0;
}