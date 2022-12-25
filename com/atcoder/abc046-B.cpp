#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,a;
    cin>>n>>k;
    a=k;
    while(--n)a*=k-1;
    cout<<a;
    return 0;
}
