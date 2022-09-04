#include "bits/stdc++.h"
using namespace std;
int num[100005];
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp=i/2+i/3+i/5;
        if(num[temp]==0){
            cnt++;
            num[temp]=1;
        }
    }
    printf("%d\n",cnt);
    return 0;
}