#include "bits/stdc++.h"
#define ll long long
#define N 100009
using namespace std;
int m[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		for(int i='a';i<='z';i++){
			m[i]=0;
		}
		for(int i=0;i<4;i++){
			char c;
			cin>>c;
			m[c]++;
		}
		int nn=0;
		for(int i='a';i<='z';i++){
			if(m[i]!=0)nn++;
		}
		cout<<nn-1<<endl;
	}
	return 0;
}
