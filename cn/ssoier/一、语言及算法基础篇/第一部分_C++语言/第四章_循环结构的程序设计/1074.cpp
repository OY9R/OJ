#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m = 0, s = 0, b, t;
	for(int i = 1; i <= 12; ++i){
		cin>>b;
		if(m + 300 >= b){
			t = m + 300 - b;
			m = t % 100;
			s += t - m;
		}else{
			cout<<-i;
			return 0;
		}
	}
	cout<<s*1.2 + m;
	return 0;
}
