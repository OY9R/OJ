#include <stdio.h>
int main()
{
    int a,b,i,res=1;
    scanf("%d%d",&a,&b);
    for(i=1;i<=b;i++)
    {
        res*=a;
        res%=7;
    }
    switch(res)
    {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        default:
            printf("Sunday\n");
            break;
    }
    return 0;
}