#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	if(!(n%3)){
		cout << "3 ";
	}
	if(!(n%5)){
		cout << "5 ";
	}
	if(!(n%7)){
		cout << "7 ";
	}
	if(n%3&&n%5&&n%7){
		cout << "n";
	}
	return 0;
}
