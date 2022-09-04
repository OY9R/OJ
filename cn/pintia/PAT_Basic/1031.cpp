#include "bits/stdc++.h"
using namespace std;
#define ll long long
int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char z[]={'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	bool flag=true;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		int ans=0;
		for(int i=0;i<17;i++){
			ans+=(s[i]-'0')*w[i];
		}
		if(s[s.length()-1]!=z[ans%11]){
			cout<<s<<endl;
			flag=false;
		}
	}
	if(flag)
		cout<<"All passed"<<endl;
	return 0;
}