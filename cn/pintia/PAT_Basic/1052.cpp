#include "bits/stdc++.h"
#define ll long long
using namespace std;
vector <string> mark[3];
int n;
int main(){
	for(int i=0;i<3;i++){
		string str;
		getline(cin,str);
		int left=0;
		for(int j=0;j<str.length();j++){
			if(str[j]=='[')
				left=j;
			if(str[j]==']')
				mark[i].push_back(str.substr(left+1,j-left-1));
		}
	}
	scanf("%d",&n);
	while(n--){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		if(a>mark[0].size()||e>mark[0].size()||b>mark[1].size()||d>mark[1].size()||c>mark[2].size()||a<=0||b<=0||c<=0||d<=0||e<=0)
			printf("Are you kidding me? @\\/@\n");
		else
			cout<<mark[0][a-1]<<"("<<mark[1][b-1]<<mark[2][c-1]<<mark[1][d-1]<<")"<<mark[0][e-1]<<endl;
	}
	return 0;
 } 