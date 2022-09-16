#include<iostream>
using namespace std;
int main()
{
	int n = 0, m = 0,t=0,b=0,c=0,p=0;
	while (cin >> n >> m)
	{
		if (n)
		{
			int b[105] = { 0 };
			int a[105] = { 0 };
			for (int i = 0; i < n; i++)cin >> a[i];
			for (int i = 0; i < n; i++)
			{
				if (m < a[i]) { t = i; p = 1; break; }
			}
			if (p == 1)
			{
				for (int i = t; i < n + 1; i++) { b[i] = a[i]; }
				a[t] = m;
				for (int i = t ; i < n + 1; i++)a[i+1] = b[i];
				for (int i = 0; i < n + 1; i++) { cout << a[i]; if (i != n)cout << " "; }
				cout <<endl;
			}
			else
			{
				a[n] = m;
				for (int i = 0; i < n + 1; i++) { cout << a[i]; if (i != n)cout << " "; }
				cout << endl;
			}
		}
		else  break; 
	}
}