#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
    cin>>n;
    bool minus=n<0;
    n=max(-n,n);
    while(n){
        m+=n%10;
        m*=10;
        n/=10;
    }
    cout<<(minus?-m:m)/10;
}