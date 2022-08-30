#include "bits/stdc++.h"
using namespace std;
int main(){
    int x,y,flag=0;
    scanf("%d %d",&x,&y);
    x=x*y;
    do{
        if(x%10==0&&flag==0);
        else if(x%10!=0&&flag==0){
            flag=1;
            printf("%d",x%10);
        }
        else
            printf("%d",x%10);  
        x/=10;
    }while(x>0);
    printf("\n");
    return 0;
 } 