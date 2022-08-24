#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
int main(){
	int m,n;
	while(cin>>m>>n)
		cout<<m/gcd(m,n)*n<<endl;
}
