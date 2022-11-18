#include<bits/stdc++.h>
using namespace std;
int main () {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool have1 = false;
        int sum=0;
        while(n--){
            int m;cin>>m;
            if(m==1)have1=true;
            sum+=m;
        }
        if(sum%2){
            cout<<"NO"<<endl;
            continue;
        }
        if(sum%4&&!have1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}