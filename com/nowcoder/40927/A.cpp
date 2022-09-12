#include<bits/stdc++.h>
using namespace std;
int m[6];
int v[]= {5,5,5,5,5,5};
int main() {
	for(int i=0; i<6; i++)
		cin>>m[i];
	int ans=0;
	for(int i=0; i<6; i++)
		ans+=m[i]*v[i];
	cout<<ans<<endl;
	return 0;
}