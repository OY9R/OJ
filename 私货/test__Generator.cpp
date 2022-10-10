#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int seed;
	cin >> seed;//读取种子
	srand(seed);
	int n=10;
	set<int> s;
	for(int i=0;i<n;i++)
		s.insert(rand()%n);
	cout<<s.size()<<endl;
	for(auto it=s.begin();it!=s.end();it=next(it))
		cout<<*it<<' ';
	cout<<endl;
	return 0;
}
