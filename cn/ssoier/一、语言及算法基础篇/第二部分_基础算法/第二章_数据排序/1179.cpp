#include<bits/stdc++.h>
using namespace std;
struct Stu
{
	int id, Chinese, score;
};
bool cmp(Stu d1, Stu d2)
{
    if(d1.score == d2.score && d1.Chinese == d2.Chinese)
        return d1.id < d2.id;
    else if(d1.score == d2.score)
        return d1.Chinese > d2.Chinese;
    else
        return d1.score > d2.score;
}
int main()
{
   	int n, a, b, c;
   	cin >> n;
	Stu d[305]; 
   	for(int i = 1; i <= n; ++i)
   	{
   		cin >> a >> b >> c;
   		d[i].id = i;
   		d[i].Chinese = a;
   		d[i].score = a+b+c;
	}
	sort(d+1, d+1+n, cmp); 
	for(int i = 1; i <= 5; ++i)
		cout << d[i].id << ' ' << d[i].score << endl;
    return 0;
}