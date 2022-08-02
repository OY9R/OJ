#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, h, m;
int mm[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin>>mm[i];
			switch(mm[i]%10) {
				case 0:break;
				case 1: case 4: case 8:
				case 2:mm[i]=((mm[i]/10)%2)*10+2;break;
				case 6: case 7: case 9:
				case 3:mm[i]=((mm[i]/10+1)%2)*10+2;break;
				case 5:mm[i]+=5;break;
			}
		}
		bool f=true;
		int tmp = mm[0];
		for (int i = 1; i < n; ++i){
			if(tmp!=mm[i]){
				f=false;
				break;
			}
		}
		if(f){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
