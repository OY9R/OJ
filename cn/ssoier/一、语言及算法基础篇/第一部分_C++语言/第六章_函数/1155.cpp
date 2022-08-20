#include<bits/stdc++.h>
using namespace std;
//判断大于等于2的整数n是不是质数 
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
//判断三位数n是否是回文数字 
bool isHuiwen(int n)
{
	return n%10 == n/100;
}
int main()
{
	for(int i = 100;i <= 999; ++i)
	{
		if(isPrime(i) && isHuiwen(i))
			cout << i << endl;
	}
	return 0;
}