#include<bits/stdc++.h>
using namespace std;
bool np[50<<20];
int ps[6<<20];
int get() {
    int k=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        k=(k<<1)+(k<<3)+(c^48);
    return k;
}
int main(){
    ps[0]=2;
    ps[1]=3;
    int pn=2,n=get(),q=get(),k;
    for(int i=5,b=0;i<=n;i+=2+2*b,b=!b){
        if(!np[i-3>>1])
            ps[pn++]=i;
        for(int j=2;j<pn&&i*ps[j]<=n;j++){
            np[i*ps[j]-3>>1]=1;
            if(i%ps[j]==0)break;
        }
    }
    for(;q--;cout<<ps[k-1]<<'\n')k=get();
    return 0;
}