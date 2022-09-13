#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int i=0;
		while(i<n){
			if(i<n-2&&s[i+2]=='0'&&!(i<n-3&&s[i+3]=='0')){
				char m=(s[i]-'0')*10+s[i+1]-'0'+'a'-1;
				cout<<m;
				i+=3;
			}else{
				cout<<(char)(s[i]-'0'+'a'-1);
				i++;
			}
		}
		cout<<endl;
	}
	return 0;
}
