#include<bits/stdc++.h>
using namespace std;
#define N 155
struct HPN
{
	int a[N];
	HPN()
	{
		memset(a, 0, sizeof(a));
	}
	HPN(char s[])
	{
		memset(a, 0, sizeof(a));
		a[0] = strlen(s);
		for(int i = 1; i <= a[0]; ++i)
	        a[i] = s[a[0] - i] - '0';
	}
	int& operator [] (int i)
	{
		return a[i];
	}
	void setLen(int i)//确定数字位数
	{
		while(a[i] == 0 && i > 1)
	        i--;
	    a[0] = i;
	}
	void operator *= (int b)//a *= b
	{
		int c = 0, i;
		for(i = 1; i <= a[0]; ++i)
		{
		    a[i] = a[i]*b + c;
		    c = a[i] / 10;
		    a[i] %= 10; 
		}
		while(c > 0)
		{
		    a[i] = c % 10;
		    c /= 10;
		    i++;
		}
		setLen(i); 
	}
	void operator += (HPN b)//高精加高精
    {
        int c = 0, i;
        for(i = 1; i <= a[0] || i <= b[0]; ++i)
        {
            a[i] += b[i] + c;
            c = a[i] / 10;
            a[i] %= 10;
        }
        a[i] = c;
        setLen(i);
    }
	void show()
	{
		for(int i = a[0]; i >= 1; --i)
        	cout << a[i];
	}
};
int main()
{
	int n;
	cin >> n;
	HPN s("0"), a("1");//s = 0, a = 1 
	for(int i = 1; i <= n; ++i)
	{
		a *= i;//高精乘低精
        s += a;//高精加高精
    }
	s.show();
	return 0;
}