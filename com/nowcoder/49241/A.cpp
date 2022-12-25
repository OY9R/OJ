#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    while(cin>>n){
        if(n%6!=3)cout<<n;
        else cout<<n/3*2;
        cout<<endl;
    }
    return 0;
}