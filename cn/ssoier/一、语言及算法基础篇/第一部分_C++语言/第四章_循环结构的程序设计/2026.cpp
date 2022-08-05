#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long s,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        t=1;
        for(int j=2;j<=i;j++)
            t*=j;
        s+=t;
    }
    cout<<s;
    return 0;
}