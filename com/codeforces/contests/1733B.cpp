#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		if(x&&y||!(x||y)||(n-1)%max(x,y)!=0){
			cout<<-1<<endl;
			continue;
		}
		int a=1,tt=0;
		for(int i=2;i<=n;i++){
			if(tt==max(x,y)){
				a=i;
				tt=0;
			}
			cout<<a<<' ';
			tt++;
		}
		cout<<endl;
	}
	return 0;
}