#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x3f3f3f3f,mod=1e9+7;
db dis(db x1,db y1,db x2,db y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void solve(){
    db x1,x2,y1,y2,r1,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    db ax=x1,ay=y1,bx=x2,by=y2;
    while(true){
        db x=(ax+bx)/2;
        db y=(ay+by)/2;
        db d1=dis(x1,y1,x,y);
        db d2=dis(x2,y2,x,y);
        if(d1<=r1&&d2<=r2){printf("%f %f\n",x,y);return;}
        if(d1<=r1)ax=x,ay=y;
        if(d2<=r2)bx=x,by=y;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}