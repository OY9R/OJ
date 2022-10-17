#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int seed;
	cin >> seed;//读取种子
	srand(seed);
	int n=rand()%50;
	for(int i=0;i<n;i++){
		cout<<(char)(rand()%26+(rand()%2?'a':'A'));
	}
	cout<<endl;
	return 0;
}
