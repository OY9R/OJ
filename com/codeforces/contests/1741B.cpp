#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if(n%2){
			if(n<5)
				cout<<-1;
			else{
				for(int i=4;i<=n;i++)
					cout<<i<<' ';
				cout<<"1 2 3 ";
			}
		}else{
			for(int i=n;i>=1;i--)
				cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}
