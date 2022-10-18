#include<bits/stdc++.h>
using namespace std;
#define N 105 
bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); ++i)
		if(n%i == 0) return false;
	return true;
}
int main(){
	string s;
	cin >> s;
	int chNum[128] = {}, len = s.size(), maxn = 0, minn = N;
	for(int i = 0; i < len; ++i)
		chNum[s[i]]++; 
	for(char i = 'a'; i <= 'z'; ++i)
		if(chNum[i] > 0){
			maxn = max(maxn, chNum[i]);
			minn = min(minn, chNum[i]);
		}
	if(isPrime(maxn - minn)) cout << "Lucky Word" << endl << maxn - minn;
	else cout << "No Answer" << endl << 0;
	return 0;
}