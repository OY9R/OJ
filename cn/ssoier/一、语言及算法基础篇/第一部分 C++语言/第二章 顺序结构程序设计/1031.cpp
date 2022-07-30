#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	printf("%d%d%d",n%10,n/10%10,n/100);
	return 0;
}
