#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k=1;
		cin>>n;
		vector<long long> a(n+1);
		a[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>0;i--){
			a[i]-=a[i-1];
		}
		vector<long long> b(n+1);
		fill(b.begin(),b.end(),0);
		int j=1;
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				if(b[-a[i]]==0)
					b[-a[i]]=i;
				else
					for(;j<=n&&a[i]<0;j++)
						if(b[j]==0) b[j]=i,a[i]+=j;
			}
		}
		for(int i=1;i<=n;i++)
			if(b[i])
				cout<<b[i]<<' ';
			else
				cout<<"1 ";
		cout<<endl;
	}
	return 0;
}