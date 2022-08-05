#include<bits/stdc++.h>
using namespace std;
int a,b;
unsigned long long s,t;
int main(){
    cin>>a>>b;
    if(a<=2&&b>=2) cout<<2<<endl;
    for(int i=a/2*2+1;i<=b;i+=2){
        bool flag=true;
        for(int j=2;j<=sqrt(i)&&flag;j++)
            if(i%j==0)
                flag=false;
        if(flag)
            cout<<i<<endl;
    }
    return 0;
}