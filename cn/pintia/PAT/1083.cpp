#include "bits/stdc++.h"
using namespace std;
int n,m[10005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        m[abs(i-t)]++;
    }
    for(int i=10004;i>=0;i--)
        if(m[i]>=2)
            printf("%d %d\n",i,m[i]);
    return 0;
}