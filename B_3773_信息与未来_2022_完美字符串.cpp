#include <bits/stdc++.h>
using namespace std;

int main(){
	int t[26]={0},a=0,minn=INT_MAX;
	int n;
	cin>>n;
	string s[n+1];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int l=1,m=0,i=1;i<=n;i++){
	    m+=s[i].size();
	    for(char c:s[i])
	        a+=t[c-'a']++==0;
        bool flag=0;
	    while(a>=26){
	        for(char c:s[l])
	            a-=--t[c-'a']==0;
            m-=s[l++].size();
            flag=1;
        }
	    if(flag){
            minn=min(minn,(int)s[l-1].size()+m);
        }
	}
	cout<<minn<<endl;
	return 0;
}