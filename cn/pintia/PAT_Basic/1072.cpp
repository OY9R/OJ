#include "bits/stdc++.h"
#define ll long long
using namespace std;
int ban[10009];
int cnt,s;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int tmp;
		cin>>tmp;
		ban[tmp]=1;
	}
	for(int i=0;i<n;i++){
		string name;
		int t,f=0;
		cin>>name>>t;
		for(int j=0;j<t;j++){
			int tmp;
			cin>>tmp;
			if(ban[tmp]==1){
				cnt++;
				if(f==0){
					cout<<name<<':';
					f=1;
				}
				printf(" %04d",tmp);
			}
		}
		if(f==1){
			s++;
			cout<<endl;
		}
	}
	printf("%d %d\n",s,cnt);
	return 0;
}
