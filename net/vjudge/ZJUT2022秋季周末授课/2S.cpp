#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	string s;
	while(getline(cin,s)) {
		if(s.length()==0)break;
		int i=0;
		while(s[i]==' ')i++;
		cout<<(char)toupper(s[i++]);
		while(i<s.length()) {
			while(s[i]!=' '&&i<s.length())cout<<(char)tolower(s[i++]);
			if(i>=s.length())break;
			cout<<' ';
			while(s[i]==' ')i++;
			if((s[i]=='i'||s[i]=='I')&&(i+1==s.length()||!isalpha(s[i+1])))
				cout<<(char)toupper(s[i++]);
		}
		cout<<endl;
	}
	return 0;
}