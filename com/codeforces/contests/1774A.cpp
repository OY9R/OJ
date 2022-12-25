#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        string s;
        cin>>s;
        int flag=s[0]-'0';
        for(int i=1;i<n;i++){
            if(s[i]-'0'&&flag)cout<<'-',flag=0;
            else if(s[i]-'0'&&!flag)cout<<'+',flag=1;
            else if(!(s[i]-'0'))cout<<'+';
        }
		cout<<endl;
	}
	return 0;
}