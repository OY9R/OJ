#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int seed;
	cin >> seed;//读取种子
	srand(seed);
	string s;
	int n=rand()%20;
	int m=rand()%20;
	for(int i=0;i<n;i++)
		s+=(char)('a'+rand()%26);
	for(int i=0;i<m;i++)
		cout<<s;
	cout<<"\n.\n";
	

	return 0;
}
