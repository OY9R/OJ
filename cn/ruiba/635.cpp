#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    while(true){
        char op='+';
        ll suma=0,sumb=1;
        ll a=114514,b;
        while(scanf("%lld/%lld",&a,&b)==2){
            if(sumb<0)suma=-suma,sumb=-sumb;
            if(op=='-')a=-a;
            ll g=__gcd(sumb,b);
            ll tmp=sumb/g*b;
            suma=tmp/b*a+tmp/sumb*suma;
            sumb=tmp;
            //cout<<suma<<'/'<<sumb<<endl;
            scanf("%c",&op);
            if(op=='\n')break;
        }
        if(a==114514)break;
        ll g=__gcd(abs(suma),sumb);
        cout<<suma/g;
        if(sumb!=g)
            cout<<'/'<<sumb/g;
        cout<<endl;
    }
    return 0;
}