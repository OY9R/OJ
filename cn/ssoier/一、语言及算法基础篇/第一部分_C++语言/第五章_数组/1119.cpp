#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[6][6], m, n;
	for(int i = 1; i <= 5; ++i)//输入矩阵
		for(int j = 1; j <= 5; ++j)
			cin >> a[i][j];
	cin >> m >> n;
	for(int j = 1; j <= 5; ++j)//遍历列，交换第m行与第n行
		swap(a[m][j], a[n][j]);
	for(int i = 1; i <= 5; ++i)//输出矩阵
	{
		for(int j = 1; j <= 5; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}