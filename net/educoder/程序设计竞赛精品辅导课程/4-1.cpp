 #include <stdio.h> 
 int main()
{
	int n,len; int num[15];
	while(scanf("%d",&n)!=EOF)
	{	// 辗转相除法的实现
	    /*begin*/
        len=0;
        while(n>0){
            num[len++]=n&1;
            n>>=1;
        }
        while(--len>=0){
            printf("%d",num[len]);
        }
        printf("\n");
        /*end*/
	}
	return 0;
}