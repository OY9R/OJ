#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
bool is_prime(LL x){
    if(x<2) return false;
    if(x<4) return true;
    for(LL i=2;i<=sqrt(x);i++)
        if(x%i==0)return false;
    return true;
}
int sum(LL x){
    return x==0?0:x%10+sum(x/10);
}
LL gcd(LL x,LL y){
    if(x<y)return gcd(y,x);
    return x%y==0?y:gcd(y,x%y);
}
bool cmp(pair<int,long> x,pair<int,long> y){
    if(x.first!=y.first)return x.first<y.first;
    return x.second<y.second;
}
int main(){
    LL n,k,m,A,num,g;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Case "<<i<<endl;
        cin>>k>>m;
        vector<pair<int,LL>> res;
        LL len=pow(10,k);
        for(LL i=pow(10,k-1)+99;i<len;i+=100){
            if(sum(i)!=m)continue;
            num=sum(i+1);
            g=gcd(m,num);
            if(is_prime(g)&&g>2)res.emplace_back(num,i);
        }
        if(res.empty())cout<<"No Solution"<<endl;
        sort(res.begin(),res.end(),cmp);
        for(auto x:res)cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
