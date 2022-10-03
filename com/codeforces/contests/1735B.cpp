#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int min=0,ans=0;
		while(n--){
			int in;
			cin>>in;
			if(min==0){
				min=in;
				continue;
			}
			ans+=in/((min<<1)-1);
			ans-=in%((min<<1)-1)==0;
			//while(in>=min<<1)in-=(min<<1)-1,ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}