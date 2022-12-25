#include<bits/stdc++.h>
using namespace std;
int main(){
		int n,q;
		cin>>n>>q;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		vector<int> b(n+1);
		for(int i=1;i<=n;i++)b[i]=(b[i-1]^a[i]);
		while(q--){
			int l,r;
			cin>>l>>r;
			int ans;
			if(l==r&&a[l]==0)ans=0;
			else if(r-l==1&&a[l]==0&&a[r]==0)ans=0;
			else if((r-l)%2==0&&(b[r]^b[l-1])==0){
				ans=1;
			}else if((r-l)%2==1&&(b[r]^b[l-1])==0){
				for(int i=l+2;i<r;i+=2){
					if((b[i]^b[l-1])==0){
						ans=2;
						break;
					}
				}
				if(ans!=2){
					for(int i=r-2;i>l;i-=2){
						if((b[i]^b[l-1])==0){
							ans=2;
							break;
						}
					}
					if(ans!=2)ans=-1;
				}
			}else ans=-1;
			cout<<ans<<endl;
		}
	return 0;
}