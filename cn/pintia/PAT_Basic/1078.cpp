#include "bits/stdc++.h"
#define ll long long
using namespace std;
void C(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		int t=i;
		while(str[i]==str[i+1])
			i++;
		if(t-i!=0)
			printf("%d",i-t+1);
		printf("%c",str[i]);
	}
}
void D(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		int temp=0,t=i;
		while(str[i]>='0'&&str[i]<='9'){
			temp=temp*10+str[i]-'0';
			i++;
		}
		if(temp==0)
			printf("%c",str[i]);
		else
			for(int j=0;j<temp;j++)
				printf("%c",str[i]);
	}
}
int main(){
	char c;
	c=getchar();
	getchar();
	if(c=='C')
		C();
	else if(c=='D')
		D();
	return 0;
 } 