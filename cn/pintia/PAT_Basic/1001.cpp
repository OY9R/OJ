#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, x, t;
ll a[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m=0;
	cin>>n;
	while(n!=1){
		m++;
		if(n%2){
			n=(n*3+1)/2;
		}else{
			n/=2;
		}
	}
	cout<<m<<endl;
	return 0;
}

