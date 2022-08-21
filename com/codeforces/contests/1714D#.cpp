#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, h, m;
int sm[101];
bool mc[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin>>ss;
			int fi=0;
			while(fi!=-1){
				fi=s.find(ss);
				if (fi!=-1){
					for(int j=fi;j<ss.length();j++){
						sm[j]=i;
					}
				}
			}
			bool f=true;
			for(int j=0;j<s.length();j++){
				if(sm[j]==0){
					f=false;
					break;
				}
			}
			if(f){
				for(int j=0;j<s.length();j++){
				if(sm[j]==0){
					f=false;
					break;
				}
			}
			}
		}
	}
	return 0;
}
