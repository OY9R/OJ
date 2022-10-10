#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	if(s.size()<2){
		cout<<-1;
		return 0;
	}
	//cout<<*(s.begin())<<*(next(s.begin()));
	if(s.size()==2&&s[0]%2+s[1]%2==1){
		cout<<-1;
		return 0;
	}
	int max11=-1,max12=-1,max21=-1,max22=-1;
	for(auto it=s.begin();it!=s.end();it=next(it)){
		if(*it&1){
			if(max11<*it){
				max12=max11;
				max11=*it;
			}
		}else{
			if(max21<*it){
				max22=max21;
				max21=*it;
			}
		}
	}
	//cout<<max11<<max12<<max21<<max22;
	if(max12!=-1)max12+=max11;
	if(max22!=-1)max22+=max21;
	cout<<max(max12,max22);
	return 0;
}