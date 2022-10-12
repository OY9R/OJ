#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int seed;
	cin >> seed;//读取种子
	srand(seed);
	int n=1<<(rand()%10);
	vector<int> m(n);
	for(int i=0;i<n;i++)
		m[i]=i+1;
	for(int i=0;i<n;i++)
		swap(m[i],m[rand()%n]);
	cout<<1<<endl;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<m[i]<<' ';
	cout<<endl;
	return 0;
}
