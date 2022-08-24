#include "bits/stdc++.h"
#define ll long long
using namespace std;
bool test(char c1,char c2){
	if(c1==c2)return false;
	if(c1=='+'&&(c2>='A'&&c2<='Z'))return false;
	else if(c2>='a'&&c2<='z')
		if(c2+'A'-'a'==c1)return false;
		else return true;
	else return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	if(s1==""){
		cout<<s2;
		return 0;
	}
	for(int i=0;i<s2.length();i++){
		bool flag=true;
		for(int j=0;j<s1.length();j++)
			flag=flag&&test(s1[j],s2[i]);
		if(flag)
			cout<<s2[i];
	}
	cout<<endl;
	return 0;
}
