#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n==2) cout<<"OK";
        else cout<<"An invalid response was received from the upstream server";
        if(t!=0) cout<<'\n';
    }
}