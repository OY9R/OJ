#include "bits/stdc++.h"
using namespace std;
int main(){
    int m,x,y,m1,m2,flag=1;
    double m3;
    scanf("%d %d %d",&m,&x,&y);
    for(m1=99;m1>=10;m1--){
        m2=m1%10*10+m1/10;
        m3=1.0*abs(m1-m2)/x;
        if(m3*y==m2){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("No Solution\n");
        return 0;
    }
    printf("%d ",m1);
    if(m>m1)printf("Gai ");
    else if(m==m1)printf("Ping ");
    else printf("Cong ");
    if(m>m2)printf("Gai ");
    else if(m==m2)printf("Ping ");
    else printf("Cong ");
    if(m>m3)printf("Gai\n");
    else if(m==m3)printf("Ping\n");
    else printf("Cong\n");
    return 0;
}