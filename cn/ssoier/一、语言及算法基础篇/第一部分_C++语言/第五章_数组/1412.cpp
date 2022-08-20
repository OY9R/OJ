#include<bits/stdc++.h>
using namespace std;
bool isClassA(int n)
{
	int s1 = 0, s0 = 0;
	for(int a = n; a > 0; a /= 2)
	{
		if(a % 2 == 1)
			s1++;
		else
			s0++;
	}	
	return s1 > s0;
}
int main()
{
	int ctA = 0, ctB = 0;
   	for(int i = 1; i <= 1000; ++i)
   	{
   		if(isClassA(i))
   			ctA++;
   		else
   			ctB++;
    }
    cout << ctA << ' ' << ctB;
	return 0;
}