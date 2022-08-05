#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long s,t;
int main(){
    for(int i=0;i<=20;i++)
        for(int j=0;j<=33;j++)
            for(int k=0;k<=99;k+=3)
                if(i+j+k==100&&5*i+3*j+k/3==100)
                    cout<<i<<' '<<j<<' '<<k<<endl;
    return 0;
}