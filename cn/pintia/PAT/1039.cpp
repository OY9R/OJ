#include "bits/stdc++.h"
#define ll long long
using namespace std;
string tar;
string str;
int num[205];
int main(){
	cin>>tar>>str;
	int flag=1,cnt=0,cntt=0;
	for(int i=0;i<tar.length();i++)
		num[tar[i]-'0']++;
	for(int i=0;i<str.length();i++)
		num[str[i]-'0']--;
	for(int i=0;i<122;i++){
		if(num[i]<0){
			flag=0;
			cntt+=num[i];
		}
		cnt+=num[i];
	}
	if(flag==1)
		printf("Yes %d\n",cnt);
	else
		printf("No %d\n",(-1)*cntt);
	return 0;
 } 