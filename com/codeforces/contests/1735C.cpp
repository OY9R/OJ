#include<bits/stdc++.h>
using namespace std;
char m1[26],m2[26];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,tot=0;
		cin>>n;
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		while(n--){
			char c;
			cin>>c;
			if(m1[c-'a'])cout<<m1[c-'a'];
			else{
				for(int i=0;i<26;i++){
					if(c!=i+'a'&&!m2[i]){
						int j=i;
						bool flag=true;
						if(tot!=25)
						while(m1[j]){
							if(m1[j]==c){
								flag=false;
								break;
							}
							j=m1[j]-'a';
						}
						if(flag){
							m2[i]=c;
							m1[c-'a']=i+'a';
							tot++;
							cout<<m1[c-'a'];
							break;
						}
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}