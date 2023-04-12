#include<bits/stdc++.h>
using namespace std;
int ans[5000050],n;
inline int isleap(int x){
    return x%400==0||(x%4==0&&x%100!=0);
}
inline int check(int x){
    string s=to_string(x);
    return s.find("202")!=string::npos;
}
inline void init(){
    for(int i=2000;i<=9999;i++){
        for(int j=1;j<=12;j++){
            for(int k=1;k<=31;k++){
                if(!isleap(i)&&j==2&&k>28)break;
                if(j==2&&k>29)break;
                if(j==4||j==6||j==9||j==11){
                    if(k>30)break;
                }
                int x=i*10000+j*100+k;
                if(check(x))ans[++n]=x;
            }
        }
    }
}
void solve(){
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int x=a*10000+b*100+c,y=d*10000+e*100+f;
    int z=lower_bound(ans+1,ans+1+n,x)-ans;
    int w=upper_bound(ans+1,ans+1+n,y)-ans;
    cout<<w-z<<endl;
}
int main(){
	int n;cin>>n;
    init();
    while(n--)solve();
    return 0;
}