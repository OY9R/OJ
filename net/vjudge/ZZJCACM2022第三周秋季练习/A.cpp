#include<bits/stdc++.h>
using namespace std;
bool isa(char c){
	if(c>='a'&&c<='z')return true;
	if(c>='A'&&c<='Z')return true;
	return false;
}
int main() {
	string s;
	while(getline(cin,s)){
		s+=' ';
		int i=0,len=s.length();
		bool flag=true,first=true;
		while(i<len){
			while(s[i]==' ')i++;
			if(i>=len)break;
			if(!first)cout<<' ';
			if((s[i]=='I'||s[i]=='i')&&!isa(s[i+1])||flag){
				cout<<(char)toupper(s[i++]);
				flag=false;
			}
			while(s[i]!=' '&&i<len)cout<<(char)tolower(s[i++]);
			if(s[i-1]=='.')flag=true;
			first=false;
		}
		cout<<endl;
	}
	return 0;
}