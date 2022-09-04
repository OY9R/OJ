#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans;
    cin>>a>>b;
    ans=a+b;
    char m[10];
    sprintf(m,"%d",ans);
    int l=strlen(m);
    for(int i=0;i<l;i++){
        printf("%c",m[i]);
        if(i!=l-1&&!(i==0&&m[0]=='-')&&(l-i+2)%3==0)
            printf(",");
    }
    return 0;
}