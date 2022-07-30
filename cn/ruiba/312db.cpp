#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define maxn 2000
ll m[]={0,10,25,39,77,679,6788,68889,2677889,26888999,3778888999};
/*
1 11
2 25
3 39
4 77
5 679
6 6788
7 68889
8 2677889
9 26888999
10 3778888999
*/
int main() {
	int n;
	while(cin>>n){
		cout<<m[n]<<endl;
	}
	return 0;
}
