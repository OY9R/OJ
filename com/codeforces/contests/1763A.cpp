#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int maxn=0,minn=INT_MAX;
        for(int i=0;i<n;i++){
            maxn=maxn|a[i];
            minn=minn&a[i];
        }
        cout<<maxn-minn;
		cout<<endl;
	}
	return 0;
}