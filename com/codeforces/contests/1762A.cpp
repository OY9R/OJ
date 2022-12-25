#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        int sum=0,minx=INT_MAX;
        for(int i=0;i<n;i++){
            int x;cin>>x;sum+=x;
            minx=min(minx,x&1?~x&-~x:x&-x);
        }
        if(sum&1){
            int ans=0;
            while(~minx&1){
                minx>>=1;
                ans++;
            }
            cout<<ans;
        }
        else cout<<0;
		cout<<endl;
	}
	return 0;
}