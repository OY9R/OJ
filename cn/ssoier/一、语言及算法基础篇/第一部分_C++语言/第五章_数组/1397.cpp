#include <stdio.h>
int calculate(int x,char op,int y)
{
	int z;
	switch(op)
	{
		case '+':
			z=x+y;
			break;
		case '-':
			z=x-y;
			break;
		case '*':
			z=x*y;
			break;
		case '/':
			z=x/y;
			break;
		case '%':
			z=x%y;
			break;
	}
    return z;
}
int main()
{
    int a,b,op;
    scanf("%d%c%d",&a,&op,&b);
    printf("%d\n",calculate(a,op,b));
    return 0;
}