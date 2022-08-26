#include "bits/stdc++.h"
#define ll long long
using namespace std;
int cnt[30];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(int i=0;i<s.length();i++)
		if(s[i]>='a'&&s[i]<='z')
			cnt[s[i]-'a']++;
	int m=0;
	char c;
	for(int i=0;i<26;i++){
		if(cnt[i]>m){
			m=cnt[i];
			c=i+'a';
		}
		if(cnt[i]==m)
			c=min(c,(char)(i+'a'));
	}
	cout<<c<<' '<<m<<endl;
	return 0;
}
