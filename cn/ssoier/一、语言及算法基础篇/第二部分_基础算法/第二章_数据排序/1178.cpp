#include<bits/stdc++.h>
using namespace std;
struct Stu
{
    char name[25];
    int score;
};
bool cmp(Stu a, Stu b)
{
    return a.score > b.score || a.score == b.score && strcmp(a.name, b.name) < 0;
}
int main()
{
    Stu stu[25];
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> stu[i].name >> stu[i].score;
	sort(stu+1, stu+1+n, cmp);	 
    for(int i = 1; i <= n; ++i)
		cout << stu[i].name << ' ' << stu[i].score << endl;
	return 0;
}