#include<bits/stdc++.h>
using namespace std;
//求数字n的因子之和 
int sum(int n)
{
	int s = 0;
	for(int i = 1; i < n; ++i)
		if(n % i == 0)
			s += i;
	return s;
}
int main()
{
	int a, b;
    for(int i = 2; true; ++i)
    {
    	a = i;
    	b = sum(a);
    	if(a != b && a == sum(b))
    	{
    		if(a < b)//输出a和b，根据题目要求，先输出小的数字，再输出大的数字 
    			cout << a << ' ' << b;
    		else
    			cout << b << ' ' << a;
			break;
    	}
	}
	return 0;
}