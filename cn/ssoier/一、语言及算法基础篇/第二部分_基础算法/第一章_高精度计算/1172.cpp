#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> mul(vector<int> &a, int b){
	vector<int> c;
	for (int i=0,t=0;i<a.size()||t;i++){
		if (i<a.size())
			t+=a[i] * b;
		c.push_back(t % 10);
		t/=10;
	}
	while(c.size()>1&&c.back()==0)c.pop_back();
	return c;
}

int main()
{
	int n;
	cin >> n;
	vector<int> res;
	res.push_back(1);
	for (int i=1;i<=n;i++)
		res=mul(res,i);
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
	cout << endl;
	return 0;
}
