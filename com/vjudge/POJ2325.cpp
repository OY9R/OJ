#include <stdio.h>
#include <string.h>

char str[10000];
char temp[10000];

int dir(int i)//主要模拟一个数除以一个个位数的过程，就是除法计算图的模拟
{
    memset(temp,'\0',sizeof temp);
    int j;
    int mod=0;
    for(j=0;str[j]!='\0';j++)
    {
        mod=mod*10+str[j]-'0';
        temp[j]=mod/i+'0';
        mod=mod%i;
    }
    temp[j]='\0';
    j=0;
    while(str[j]=='0')
        j++;
    if(mod)
        return 0;
    else
    {
        strcpy(str,temp+j);
        return 1;
    }
}

int main()
{
    while(1)
    {
        scanf("%s",str);
        int i;
        if(str[0]=='-')
            break;
        if(str[1]=='\0')
        {
            printf("1%s\n",str);
            continue;
        }
        int k=0;
        int ans[10000];
        for(i=9;i>1;i--)//前面的数一定是大于或等于后面的数    这儿体现贪心
        {
            while(dir(i)) //这儿的while为等于时判断
                ans[k++]=i;
        }
        if(strlen(str)>1)
        {
            printf("There is no such number.\n");
            continue;
        }
        for(i=k-1;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
        memset(str,'\0',sizeof str);
    }
   
    return 0;
}