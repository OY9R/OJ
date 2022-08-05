#include<bits/stdc++.h>
using namespace std;
#define N 110
int a[N];
int main(){
    int i,n,m,f=0,t=0,s=0;
    scanf("%d%d",&n,&m);
    do{
        t++;
        if(t==n+1)t=1;
        if(a[t]==0)s++;
        if(s==m){
            s=0;
            printf("%d ",t);
            a[t]=1;
            f++;
        }
    }while(f!=n);
    return 0;  
}