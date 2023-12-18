//反素数:N以内约数个数最多的数字中最小的一个
//blog:https://www.cnblogs.com/correct/p/16548405.html
//test:https://www.acwing.com/problem/content/200/
//不需打印
#include <bits/stdc++.h>
using namespace std;
int prime[]={0,2,3,5,7,11,13,17,19,23,27,29,31},n;
typedef long long ll;ll mx,ans;
void dfs(ll number,ll d,int m,int lim)
{
	if(m<11)for(ll i=0,t=1;i<=lim,number*t<=n;i++)
	    dfs(number*t,d*(i+1),m+1,i),t*=prime[m+1];	
	else if(d>mx)mx=d,ans=number;
	else if(d==mx)ans=min(ans,number);
}
int main(){cin>>n;mx=ans=-1;dfs(1,1,0,31);cout<<ans<<'\n';}
