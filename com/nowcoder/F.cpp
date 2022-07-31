#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define MAXN 1000001
string name;
int n,m;

int main() {
	cin>>n;
	while(n--){
		cin>>name;
		if(name.find("month")!=-1) m++;
	}
	cout<<m<<endl;
	return 0;
}
