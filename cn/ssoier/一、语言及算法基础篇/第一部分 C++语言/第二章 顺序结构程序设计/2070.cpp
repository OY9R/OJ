#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cout << n/100 + (n%10)*100 + n/10%10*10 << endl;
	return 0;
}
