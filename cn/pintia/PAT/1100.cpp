#include <bits/stdc++.h>
using namespace std;
map<string,string>ans,a,b;
string s;
int n,m;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		a[s]=s.substr(6,8);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s;
		if(a[s]!="")ans[a[s]]=s;
		b[s.substr(6,8)]=s;
	}
	if(ans.size())
		printf("%d\n%s",ans.size(),ans.begin()->second.c_str());
	else
		printf("%d\n%s",ans.size(),b.begin()->second.c_str());
	return 0;
}