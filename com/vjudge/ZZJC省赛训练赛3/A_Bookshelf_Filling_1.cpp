#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,n,m,h;

int main(){
	int t,p;
	cin>>t;
	while(t--)
    {
      cin>>a>>b>>n>>m>>h;
      int ans=n;
      int p=n/b;
      m=m-(h-a)*p;
        // cout<<m<<"#"<<p<<"$";
      if(m<=0){
        ans++;
        cout<<ans<<endl;
      }else{
        m=m+(n%b);
        int q=m%h;
        ans=ans+q+m/h*b-n%b;
        cout<<ans<<endl;
      }
      // p=n%b;
      // n=n;
      // m=m;
      // m=m-(n/b)*(h-a);
      // if(m<=0)
      // {
      // n=n+1;
      // m=0;
      // }
      // int y=m-p;
      // y=max(0,y);
      // n=n+b*(m/h);
      // if(m%h+y>h)
      // n=n-
      // n=n+m%h;
      // cout<<n<<endl;
// 2#2$ 7
// 1#2$ 7
// -6#2$6
// 0#1$4
    }
	return 0;
}