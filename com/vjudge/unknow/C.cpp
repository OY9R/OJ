#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        int n=s.size();
        int l=0,r=n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                l=i;break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                r=i;break;
            }
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}