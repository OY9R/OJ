#include "bits/stdc++.h"
#define ll long long
using namespace std;
map<string,int> mm;
int main(){
	int m,n,s,t=0,f=0;
	cin>>m>>n>>s;
	t=s;
	for(int i=1;i<=m;i++){
		string str;
		cin>>str;
		if(i==t&&mm[str]==0){
			mm[str]++;
			f=1;
			t+=n;
			cout<<str<<endl;
		}
		else if(i==t&&mm[str]==1){
			for(int j=i+1;j<=m;j++){
				cin>>str;
				if(mm[str]==0){
					mm[str]++;
					cout<<str<<endl;
					i=j;
					t=j+n;
					break;
				}
			}
		}
	}
	if(f==0)
		cout<<"Keep going...\n";
	return 0;
 } 