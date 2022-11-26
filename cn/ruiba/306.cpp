#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(__int128 a) {
	if(a>9)
		print(a/10);
	putchar(a%10+'0');
}
int main(){
    int t;cin>>t;
    while(t--){
        __int128 l,r=0,n;
        ll t;cin>>t;
        n=(long long)t;
        __int128 ans=n*n;
        for(l=1;l<=n;l=r+1){
            if(n/l==0) break;
            r=min(n/(n/l),n);
            ans-=(n/l)*(l+r)*(r-l+1)>>1;
        }
        print(ans);
        cout<<'\n';
    }
    return 0;
}