#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int cmp(string a,string b){
    int n=min(a.size(),b.size());
    for(int i=0;i<n;i++){
        if(a[i]==b[i])continue;
        return a[i]>b[i]?1:-1;
    }
    if(a.size()==b.size())return 0;
    return a.size()>b.size()?1:-1;
}
inline int cmp(char a,int n,char b){
    if(n==1){
        if(a==b)return 0;
        return a>b?1:-1;
    }
    if(a<b)return -1;
    return 1;
}
void solve(){
    string s;cin>>s;
    for(int i=1;i<s.size()-1;i++){
        // for(int j=i;j<s.size()-1;j++){
        //     if(s[0])
        //     string mid=s.substr(i,j);
        //     if(cmp(s.substr(0,i),mid)*cmp(mid,s.substr(j+1))<=0){
        //         cout<<s.substr(0,i)<<' '<<mid<<' '<<s.substr(j+1)<<endl;
        //         return;
        //     }
        // }
        if(cmp(s[0],i,s[i])*cmp(s[i+1],s.size()-i-1,s[i])>=0){
            cout<<s.substr(0,i)<<' '<<s[i]<<' '<<s.substr(i+1)<<endl;
            return;
        }
    }
    cout<<":("<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}