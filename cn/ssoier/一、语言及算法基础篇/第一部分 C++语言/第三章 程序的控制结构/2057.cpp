#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m;
string week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	n--;
	if(n<0||n>6){
		cout << "input error!";
		return 0;
	}
	cout << week[n];
	return 0;
}
