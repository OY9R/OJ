#include<bits/stdc++.h>
using namespace std;
int ans[14],m[3][28]= {0},sum=0,n;
void eq(int l) {
    if(l>n) {
        sum++;
        if(sum>3) return;
        else {
            for(int i=1; i<=n; i++) printf("%d ",ans[i]);
            printf("\n");
            return;
        }
    }
    for(int i=1; i<=n; i++) {
        if((!m[0][i])&&(!m[1][l+i])&&(!m[2][l-i+n])) {
            ans[l]=i;
            m[0][i]=1; m[1][l+i]=1; m[2][l-i+n]=1;
            eq(l+1);
            m[0][i]=0; m[1][l+i]=0; m[2][l-i+n]=0;
        }
    }
}
int main() {
    scanf("%d",&n);
    eq(1);
    printf("%d",sum);
    return 0;
}