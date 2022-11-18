#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;cin>>n;
    while (n--)
    {
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        x-=a;y-=b;
        if(x<0)x=0;
        if(y<0)y=0;
        if(c>=x+y){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}