#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long s,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<'*';
        cout<<endl;
    }
    return 0;
}