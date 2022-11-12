#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,k,val;
int main() {
    cin>>n>>x>>y>>z>>k>>val;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        a[i]={(h1*y+m1)*z+s1,(h2*y+m2)*z+s2+k};
        //cout<<a[i].first<<'-'<<a[i].second<<endl;
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        if(a[i-1].second>=a[i].first){
            if(a[i-1].second>a[i].second){
                a[i].second=a[i-1].second;
            }
            a[i-1].second=a[i].first-1;
        }
    }
    if(a[n-1].second>((x-1)*y+(y-1))*z+z-1){
        a[n-1].second=((x-1)*y+(y-1))*z+z-1;
    }
    long long time=0;
    for(int i=0;i<n;i++){
        //cout<<a[i].first<<'-'<<a[i].second<<endl;
        time+=a[i].second-a[i].first+1;
    }
    cout<<time*val;
    return 0;
}