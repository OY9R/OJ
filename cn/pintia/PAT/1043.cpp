#include "bits/stdc++.h"
#define ll long long
using namespace std;
map<char,int> m;
int main(){
	string str;
	int flag=1;
	cin>>str;
	for(int i=0;i<str.length();i++)
		m[str[i]]++;
	while(1){
		if(flag==0)
			break;
		flag=0;
		if(m['P']!=0){
			printf("P");
			m['P']--;
			flag=1;
		}
		if(m['A']!=0){
			printf("A");
			m['A']--;
			flag=1;
		}	
		if(m['T']!=0){
			printf("T");
			m['T']--;
			flag=1;
		}
		if(m['e']!=0){
			printf("e");
			m['e']--;
			flag=1;
		}
		if(m['s']!=0){
			printf("s");
			m['s']--;
			flag=1;
		}
		if(m['t']!=0){
			printf("t");
			m['t']--;
			flag=1;
		}
	}
	printf("\n");
	return 0;
 } 
