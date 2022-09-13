#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int m[N];
string s;
int mm[36][N];
int main() {
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<35;i++)
			mm[i][0]=0;
		cin>>s;
		int len=s.length();
		char mmin=min(s[0],s[len-1]);
		char mmax=max(s[0],s[len-1]);
		int cnt=0;
		for(int i=1;i<len-1;i++)
			if(s[i]>=mmin&&s[i]<=mmax){
				mm[s[i]-'a'][++mm[s[i]-'a'][0]]=i;
				cnt++;
			}
		cout<<mmax-mmin<<' '<<cnt+2<<endl;
		if(s[0]<s[len-1]){
			cout<<1;
			for(int i=s[0]-'a';i<=s[len-1]-'a';i++)
				for(int j=1;j<=mm[i][0];j++)
					cout<<' '<<mm[i][j]+1;
			cout<<' '<<len;
		}else{
			cout<<1;
			for(int i=s[0]-'a';i>=s[len-1]-'a';i--)
				for(int j=1;j<=mm[i][0];j++)
					cout<<' '<<mm[i][j]+1;
			cout<<' '<<len;
		}
		cout<<endl;
	}
	return 0;
}
