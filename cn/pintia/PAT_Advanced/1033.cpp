#include<bits/stdc++.h>
using namespace std;
int main() {
    double cmax,d,davg;
    int n;
    cin>>cmax>>d>>davg>>n;
    vector<pair<double,double>> sta(n+1);
    sta[0]={d,0};
    for(int i=1;i<=n;i++)
        cin>>sta[i].second>>sta[i].first;
    sort(sta.begin(),sta.end());
    double nowdis=0,maxdis=0,nowprice=0,totalprice=0,leftdis=0;
    if(sta[0].first!=0){
        cout<<"The maximum travel distance = 0.00";
        return 0;
    }else nowprice=sta[0].second;
    while(nowdis<d){
        maxdis=nowdis+cmax*davg;
        double minpricedis=0,minprice=INT_MAX;
        int flag=0;
        for(int i=1;i<=n&&sta[i].first<=maxdis;i++){
            if(sta[i].first<=nowdis)continue;
            if(sta[i].second<nowprice){
                totalprice+=(sta[i].first-nowdis-leftdis)*nowprice/davg;
                leftdis=0;
                nowprice=sta[i].second;
                nowdis=sta[i].first;
                flag=1;
                break; 
            }
            if(sta[i].second<minprice){
                minprice=sta[i].second;
                minpricedis=sta[i].first;
            }
        }
        if(flag==0&&minprice!=INT_MAX){
            totalprice+=(nowprice*(cmax-leftdis/davg));
            leftdis=cmax*davg-(minpricedis-nowdis);
            nowprice=minprice;
            nowdis=minpricedis;
        }
        if(flag==0&&minprice==INT_MAX){
            nowdis+=cmax*davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalprice);
    return 0;
}