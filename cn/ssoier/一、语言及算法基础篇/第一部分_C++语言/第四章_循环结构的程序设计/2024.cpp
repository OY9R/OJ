#include<bits/stdc++.h>
using namespace std;
long long n,m;
int k=1;
int main(){
    cin>>n;
    while(n--){
        k=k*1992%100;
    }
    cout<<k;
    return 0;
}