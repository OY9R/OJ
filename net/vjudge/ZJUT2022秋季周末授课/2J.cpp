#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct milk{
    int ml;
    int day;
    char name[105];
    double price;
}mi[105];
int n,m;
bool cmp(milk a,milk b){
    if(a.price!=b.price)return a.price<b.price;
    else if(a.price==b.price)return a.ml>b.ml;
}
void getdata(){
    int i,a;
    char s[105];
    scanf("%d",&n);
    for(i=0,m=0;i<n;i++){
        scanf("%s %d %d",mi[m].name,&a,&mi[m].ml);
        if(mi[m].ml<200)continue;
        mi[m].day=mi[m].ml/200;
        if(mi[m].day>5)mi[m].day=5;
        mi[m].price=a/mi[m].day;
        m++;
    }
    sort(mi,mi+m,cmp);
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        getdata();
        printf("%s\n",mi[0].name);
    }
    return 0;
}