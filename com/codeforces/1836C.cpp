#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
	ll a,b,c,k;cin>>a>>b>>c>>k;
    ll cl=pow(10l,c-1),cr=pow(10l,c),cnt=0;
    // cout<<"-------------"<<endl;
    // ll tag=0;
    // for(int i=pow(10l,a-1),ir=pow(10l,a);i<ir;i++){
    //     cout<<cnt+1<<'\t';
    //     for(int j=pow(10l,b-1),jr=pow(10l,b);j<jr;j++){
    //         if(i+j>=cl&&i+j<cr)cnt++;
    //         // if(cnt==1){
    //         //     cout<<cnt<<'\t'<<i<<'+'<<j<<'='<<i+j<<endl;
    //         //     tag=i+j;
    //         // }
    //         // if(i+j==tag)cout<<cnt<<'\t'<<i<<'+'<<j<<'='<<i+j<<endl;
    //         // // if(i+j==cr-1)cout<<cnt<<'\t'<<i<<'+'<<j<<'='<<i+j<<endl;
    //     }
    //     cout<<cnt<<endl;
    // }
    if(c>a&&c>b){
        // cout<<"A\n";
        ll ai=pow(10l,a-1),step=pow(10l,b)+ai-cl,ar=pow(10l,a);k--;
        for(;k>0&&ai<ar;ai++,k-=step++);//cout<<k<<' ';
        //cout<<endl;
        if(ai>ar)cout<<-1<<endl;
        else if(k==0)cout<<ai<<" + "<<cl-ai<<" = "<<cl<<endl;
        else cout<<ai-1<<" + "<<pow(10l,b)+k<<" = "<<ai-1+pow(10l,b)+k<<endl;
    }else if(c>=a&&c>=b){
        // cout<<"B\n";
        ll ai=pow(10l,a-1),step=cr-pow(10l,a-1)-pow(10l,b-1),ar=pow(10l,a);k--;
        for(;k>0&&step>=0&&ai<ar;ai++,k-=step--);//cout<<k<<' '<<endl;
        if(step==-1||ai==ar)cout<<-1<<endl;
        else cout<<ai<<" + "<<k+1<<" = "<<ai+k+1<<endl;
    }else{
        cout<<-1<<endl;
    }

    return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}