#include <stdio.h>
#include <string.h>
#define N 2510
char s[N];
int main()
{
	int i,n,count=1;
	scanf("%d %s",&n,s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==s[i+1])
			count++;
		else
		{
			if(count>=n)
			{
				printf("%c",s[i]);
				return 0;
			}
			else
			{
				count=1;
			}
		}
	}
	printf("No\n");
	return 0;
}