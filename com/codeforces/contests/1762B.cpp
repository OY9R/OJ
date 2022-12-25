#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        vector<PII> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a.begin(),a.end());
        cout<<n-1<<'\n';
        for(int i=1;i<n;i++){
            int t1=a[i].first,t2=a[i-1].first;
            cout<<a[i].second+1<<' '<<(t1/t2+(t1%t2>0))*t2-t1<<'\n';
            a[i].first=(t1/t2+(t1%t2>0))*t2;
        }
	}
	return 0;
}