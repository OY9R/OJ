#include <cstdio>
using namespace std;
int p[50001],r[50001],n,k,ans,x,y,d;
int find(int x) {
    if(x!=p[x]) {
        int fx=find(p[x]);
        r[x]=(r[x]+r[p[x]])%3;
        p[x]=fx;
    }
    return p[x];
}
bool unionn(int d,int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx==fy)
        if((r[y]-r[x]+3)%3!=d) return 1;
        else return 0;
    p[fy]=fx;
    r[fy]=(r[x]-r[y]+d+3)%3;
    return 0;
}
main() {
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++) p[i]=i,r[i]=0;
    for(int i=1; i<=k; i++) {
        scanf("%d %d %d",&d,&x,&y);
        if(x>n||y>n||(x==y && d==2)) {ans++; continue;}
        if(unionn(d-1,x,y)) ans++;
    }
    printf("%d",ans);
}
