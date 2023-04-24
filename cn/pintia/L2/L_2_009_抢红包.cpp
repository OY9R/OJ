#include<bits/stdc++.h>
using namespace std;
struct people{
    int no,money,num;
}p[10010];
bool cmp(people a,people b){
    if(a.money!=b.money) return a.money>b.money;
    else if(a.num!=b.num) return a.num>b.num;
    else return a.no<b.no;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i].no=i;
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int num;cin>>num;
            int money;cin>>money;
            p[num].money+=money;
            p[num].num++;
            p[i].money-=money;
        }
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%d %.2lf\n",p[i].no,p[i].money/100.0);
    }
	return 0;
}