#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')a.push_back(i);
	vector<bool>mx(s.size());
	fill(mx.begin(),mx.end(),0);
	for(int i=1;i<n;i++){
		bool flag=true;
		for(int j=0;j<a.size();j++){
			//cout<<a[j]<<' ';
			bool tmp=0;
			if(a[j]-i>=0&&s[a[j]-i]=='1')tmp=1;
			if(tmp<mx[j]&&flag)break;
			if(tmp>mx[j])flag=false;
			if(!flag)mx[j]=tmp;
		}
	}
	int j=0;
	bool zero=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'&&!mx[j++]){
			if(!zero)cout<<'0';
		}else cout<<'1',zero=false;
	}
	if(zero)cout<<0;
	cout<<endl;
	return 0;
}