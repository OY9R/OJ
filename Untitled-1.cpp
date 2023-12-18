#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	for(int i=0;i<=100;i++)
		cout<<a[i];
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int m;cin>>m;
	for(int i=1;i<=n;i++)
		if(a[i]==m){
			cout<<i-1<<endl;
			return 0;
		}
	cout<<-1<<endl;
	return 0;
}