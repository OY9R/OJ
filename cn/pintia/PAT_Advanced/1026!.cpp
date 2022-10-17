#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int main() {
    int n;
    cin>>n;
    int playtimes[N];
    bool vips[N];
    for(int i=0;i<n;i++){
        int H,M,S;
        scanf("%d:%d:%d",&H,&M,&S);
        int t=H*3600+M*60+S;
        int vip;
        scanf("%d %d",&playtimes[t],vip);
        vips[t]=vip==1;
    }
    return 0;
}