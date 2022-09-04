#include "bits/stdc++.h"
#define ll long long
using namespace std;
int mp[100];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
		mp[s[i]]++;
	while(mp['S']!=0||mp['t']!=0||mp['r']!=0||mp['i']!=0||mp['n']!=0||mp['g']!=0){
		if(mp['S']!=0){
			cout<<'S';
			mp['S']--;
		}
		if(mp['t']!=0){
			cout<<'t';
			mp['t']--;
		}
		if(mp['r']!=0){
			cout<<'r';
			mp['r']--;
		}
		if(mp['i']!=0){
			cout<<'i';
			mp['i']--;
		}
		if(mp['n']!=0){
			cout<<'n';
			mp['n']--;
		}
		if(mp['g']!=0){
			cout<<'g';
			mp['g']--;
		}
	}
	return 0;
}