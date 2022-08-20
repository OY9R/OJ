#include <bits/stdc++.h>
using namespace std;
#define N 5005
struct Stu{
	int k, s;
};
bool cmp(Stu &a, Stu &b){
	if(a.s == b.s) 
		return a.k < b.k;
	else
		return a.s > b.s;
}
int main()
{
	Stu stu[N];
	int n, m, line, ct = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> stu[i].k >> stu[i].s;
	sort(stu+1, stu+1+n, cmp);
	line = stu[int(m*1.5)].s;
	for(int i = 1; i <= n; ++i)
	{
		if(stu[i].s >= line)
			ct++;
	}
	cout << line << ' ' << ct << endl;
	for(int i = 1; i <= ct; ++i)
		cout << stu[i].k << ' ' << stu[i].s << endl;
	return 0;
}