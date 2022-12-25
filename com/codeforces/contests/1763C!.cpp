#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int j=1;j<=n;j++){
            b[j]=b[j-1]+a[j];
        }
        pair<int,int> mn={a[1],1},mx={a[1],1};
        for(int i=2;i<n;i++){
            if(a[i]<mn.first)mn.first=a[i],mn.second=i;
            else if((a[i]-mn.first)*(i-mn.second+1)>b[i]-b[mn.second-1])
            if(a[i]>mx.first)mx.first=a[i],mx.second=i;
        }
		cout<<endl;
	}
	return 0;
}