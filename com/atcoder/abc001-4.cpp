#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int main() {
    int n;cin>>n;
    vector<PII> a(n),b;
    for(int i=0;i<n;i++){
        scanf("%d-%d",&a[i].first,&a[i].second);
        a[i].first=a[i].first%100+a[i].first/100*60;
        a[i].second=a[i].second%100+a[i].second/100*60;
        a[i].first=a[i].first/5*5;
        a[i].second=(a[i].second/5+(a[i].second%5>0))*5;
    }
    sort(a.begin(),a.end());
    int bn=0;
    for(int i=0;i<n;i++){
        if(bn&&a[i].first<=b[bn-1].second){
            b[bn-1].second=max(b[bn-1].second,a[i].second);
        }else{
            b.push_back(a[i]);
            bn++;
        }
    }
    for(int i=0;i<b.size();i++){
        printf("%02d%02d-%02d%02d\n",b[i].first/60,b[i].first%60,b[i].second/60,b[i].second%60);
    }
    return 0;
}