#include<bits/stdc++.h>
using namespace std;
int main() { // long long
    int n,m,k,a,b,c,d;
    cin>>n>>m>>k>>a>>b>>c>>d;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        if(x<a)a=x;
        if(x+1>c)c=x+1;
        if(y<b)b=y;
        if(y+1>d)d=y+1;
    }
    cout<<c<<' '<<a<<' '<<d<<' '<<b<<endl;
    cout<<(c-a)*2+(d-b)*2<<endl;
    return 0;
}