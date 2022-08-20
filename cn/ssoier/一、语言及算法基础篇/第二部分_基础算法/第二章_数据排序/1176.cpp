#include<bits/stdc++.h>
using namespace std;
struct Stu//学生类 
{
	int num;//学号 
	double score;//分数 
	bool operator < (const Stu &b) const
    {
        return score > b.score;
    } 
};
int main()
{
	int n, k;
	Stu stu[105];
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> stu[i].num >> stu[i].score;
	sort(stu+1, stu+1+n);
    cout << stu[k].num << ' ' << stu[k].score; 
	return 0;
}