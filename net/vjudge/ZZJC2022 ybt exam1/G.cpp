#include<bits/stdc++.h>
using namespace std;
int main() {
	double pi=1;
	int n,d=-1;
	cin>>n;
	for(double i=3;i<=n;i+=2){
		pi+=d/i;
		d=-d;
	}
	printf("%.6lf",pi*4);
	return 0;
}