#include "bits/stdc++.h"
#define ll long long
using namespace std;
char m[15]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b,ans;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int l=min(a.length(),b.length());
	if(a.length()>b.length())
		b.append(a.length()-l,'0');
	else
		a.append(b.length()-l,'0');
	for(int i=0;i<a.length();i++){
		if(i%2){
			int t=b[i]-a[i];
			while(t<0)
				t+=10;
			ans+=m[t];
		}else{
			int t=(a[i]+b[i]-2*'0')%13;
			ans+=m[t];
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}
