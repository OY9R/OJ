#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, si, sj, a[15][15];//(si,sj)输入的位置 
	scanf("%d %d %d", &n, &si, &sj);
	for(int j = 1; j <= n; ++j)//输出同一行的格子 
		printf("(%d,%d) ", si, j);
	putchar('\n');//换行 
	for(int i = 1; i <= n; ++i)//输出同一列上的格子 
		printf("(%d,%d) ", i, sj);
	putchar('\n');
	for(int i = 1; i <= n; ++i)//行号 从左上到右下 
	   for(int j = 1; j <= n; ++j)//列号 
	       if(i - j == si - sj)//在同一左上右下斜线 
	           printf("(%d,%d) ", i, j);
    putchar('\n');
    for(int i = n; i >= 1; --i)//行号 从左下到右上 
	   for(int j = 1; j <= n; ++j)//列号 
	       if(i + j == si + sj)//在同一左下右上斜线 
	           printf("(%d,%d) ", i, j);
	putchar('\n');
	return 0;
}