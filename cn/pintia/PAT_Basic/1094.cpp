#include "bits/stdc++.h"
#define ll long long
using namespace std;
bool check(int x){
	if(x==0||x==1)
		return false;
	for(int i=2;i<sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	int l,n,f=0;
	string s;
	scanf("%d %d",&l,&n);
	cin>>s;
	for(int i=0;i<=l-n;i++){
		string t=s.substr(i,n);
		int ans=stoi(t);
		if(check(ans)){
			cout<<t<<endl;
			f=1;
			break;
		}	
	}
	if(f==0)
		printf("404\n");
	return 0;
}
