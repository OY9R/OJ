#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
#define LL long long
const LL inf = (LL)1<<62;
LL dp[15];
LL aabs(LL x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
    int t,d;
    char str[10];
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        memset(dp,0,sizeof dp);
        int p=0;
        stack<LL> s;
        scanf("%s",str);
        s.push(-1);
        int flag=0;
        while(!s.empty())
        {
            scanf("%s",str);
            if(str[0]=='O')
            {
                LL d;
                scanf("%lld",&d);
                if(!flag)
                dp[p]+=aabs(s.top())*d;
            }
            else if(str[0]=='E')
            {
                if(s.top()==inf)
                {
                    flag--;
                }
                if(s.top()<0) p--;
                s.pop();
            }
            else if(str[0]=='L')
            {
                scanf("%s",str);
                if(str[0]=='n')
                {
                    if(!flag) p++;
                    if(flag) s.push(1);
                    else s.push(-aabs(s.top()));
                }
                else
                {
                    LL d=0;
                    for(int i=0;str[i];i++)
                        d=d*10+str[i]-'0';
                    if(d==0)
                    {
                        flag++;
                        s.push(inf);
                    }
                    else s.push(aabs(s.top())*d);
                }
            }
        }
        int tmp=-1;
        for(int i=11;i>=0;i--)
            if(dp[i])
            {
                tmp=i;
                break;
            }
        if(tt>1) printf("\n");
        printf("Program #%d\n",tt);
        int f=0;
        printf("Runtime = ");
        for(int i=tmp;i>=0;i--)
        {
            if(dp[i]==0) continue;
            if(f) printf("+");
            f=1;
            if(dp[i]>1 && i) printf("%lld*",dp[i]);
            if(i) printf("n");
            if(i>1) printf("^%d",i);
            if(i==0) printf("%lld",dp[i]);
        }
        if(tmp==-1) printf("0");
        printf("\n");
    }
    return 0;
}