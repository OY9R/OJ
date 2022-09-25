#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	string s;
	while(getline(cin,s)) {
		int i=0;
		bool flag=false;
		while(s[i]==' ')i++;
		if(i<s.length())
			cout<<(char)toupper(s[i++]);
		while(i<s.length()) {
			while(s[i]!=' '&&i<s.length())cout<<(char)tolower(s[i++]);
			if(i>=s.length())break;
			if(s[i-1]=='.')flag=true;
			while(s[i]==' ')i++;
			if(i<s.length())cout<<' ';
			if((s[i]=='i'||s[i]=='I')&&(i+1==s.length()||!isalpha(s[i+1]))||(flag&&i<s.length())){
				cout<<(char)toupper(s[i++]);
				flag=false;
			}
		}
		cout<<endl;
	}
	return 0;
}