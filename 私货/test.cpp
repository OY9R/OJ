#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	while(getline(cin,s) && s!=".") {
		int cnt[128] = {0};
		int g = 0,n = s.size();
		int c;
		for(auto c : s)
			cnt[c]++;
		for(auto c : cnt)
			g = __gcd(g,c);
		for(int i=1,j,k; i<n; i++) { //(不写条件空串会死循环)
			if(g%i == 0) {
				for(j=0,k=n/(g/i); j+k<n && s[j] == s[j+k]; j++);//如果k不是循环节长就会提前结束
				if(j+k == n) {//这个if应该放外面，判断for循环是否提前结束
					cout<<g/i<<'\n';
					break;
				}
			}
		}
	}
}