#include<bits/stdc++.h>
using namespace std;
//判断大于等于2的整数n是否是质数 
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
//将两位数n两数位调换 
int transform(int n)
{
	return n % 10 * 10 + n / 10;
}
int main()
{
	for(int i = 10;i <= 99; ++i)
	{
		if(isPrime(i) && isPrime(transform(i)))//如果i是质数，且i的两位调换后仍然是质数 
			cout << i << endl;
	}
	return 0; 
}