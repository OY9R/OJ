#include "bits/stdc++.h"
#define ll long long
using namespace std;
int ans,cnt1,cnt2;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++)
		if(str[i]>='A'&&str[i]<='Z')
			ans+=str[i]-'A'+1;
		else if(str[i]>='a'&&str[i]<='z')
			ans+=str[i]-'a'+1;
	while(ans>0){
		if(ans%2)cnt1++;
		else cnt2++;
		ans/=2;
	}
	cout<<cnt2<<' '<<cnt1<<endl;
	return 0;
}
