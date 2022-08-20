#include<bits/stdc++.h>
using namespace std;
void toBase(int n, int b)//将数值n转换为b进制输出 
{
	if(n == 0)//如果n是0，不输出 
		return;
	toBase(n / b, b);//将n/b的值转为b进制输出 
	if(n % b >= 10)//将n%b的值以b进制输出 
		cout << char(n % b - 10 + 'A');
	else
		cout << n % b;
}
int main()
{
	int n, b;
	cin >> n >> b;
	toBase(n, b);
	return 0;
}