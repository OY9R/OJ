#include <bits/stdc++.h>
using namespace std;
string ss[]={"ABCX","BCAX","CABX","ABXC","BCXA","CAXB","XBAC","XCBA","XACB","BXAC","CXBA","AXCB"};
int main(){
	string a,aa,b,bb;
	cin>>aa>>a>>bb>>b;
	aa=aa+a;
	bb=bb+b;
	bool fa=false,fb=false;
	for(string s:ss){
		if(aa==s)fa=true;
		if(bb==s)fb=true;
	}
	if(fa==fb)
		cout<<"YES";
	else
		cout<<"NO";
}