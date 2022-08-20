#include <bits/stdc++.h>
using namespace std;
const int N = 210;

int main()
{
	string str[N], a, b;
	int i = 0;
	char space;
	do
	{
		cin >> str[i];
		i ++;
		scanf("%c", &space);	//注意cin不会读入空格 
	}	
	while(space == ' ');
	
	cin >> a >> b;
	
	for(int k = 0; k < i; k ++ )
	{
		if(str[k] == a)	cout << b << ' ';
		else	cout << str[k] << ' '; 
	}
	return 0;
}