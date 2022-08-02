#include "bits/stdc++.h"
using namespace std;
#define ll long long
double a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	if(a > b){
		if(a > c){
			d = a;
		}else{
			d = c;
		}
	}else if(b > c){
		d = b;
	}else{
		d = c;
	}
	printf("%.2lf",d);
	return 0;
}
