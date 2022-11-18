#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        int l=a+b;
        string str;
        cin>>str;
        // printf("%d:\n",n);
        if(a%2==1&&b%2==1){
            printf("-1\n");
        }
        else{
            int q=0,f=0;
            for(int i=0;i<l/2;i++){
                if(str[i]=='?')
                {
                    q++;
                    if(str[l-i-1]=='?')q++;
                    else if(str[l-i-1]=='1'){
                        b-=2;
                        str[i]='1';
                    }
                    else {
                        a-=2;
                        str[i]='0';
                    }
                }
                else if(str[l-i-1]=='?')
                {
                    q++;
                    if(str[i]=='?')q++;
                    else if(str[i]=='1'){
                        b-=2;
                        str[l-i-1]='1';
                    }
                    else {
                        a-=2;
                        str[l-i-1]='0';
                    }
                }
                else if(str[i]!=str[l-i-1])
                {
                    printf("-1\n");
                    f=1;
                    break;
                }
                else{
                    if(str[i]=='0')a-=2;
                    else b-=2;
                }
            }
            // for(int i=0;i<l;i++)cout<<str[i];
            //     printf("\n");
            if(f==0){
                if(l%2==1){
                    if(str[l/2]=='1')b--;
                    else if(str[l/2]=='0')a--;
                }
                if(a<0||b<0){
                    printf("-1\n");
                }
                else {
                    for(int i=0;i<l/2;i++)
                    {
                        // printf("#%d %d#",a,b);
                        if(str[i]=='?'){
                            if(a>1){
                                str[i]='0';
                                str[l-i-1]='0';
                                a-=2;
                            }
                            else if(b>1){
                                str[i]='1';
                                str[l-1-i]='1';
                                b-=2;
                            }
                        }
                        
                    }
                    if(l%2==1&&a+b>1)printf("-1\n");
                    else{
                        if(l%2==1&&str[l/2]=='?'){
                            // printf("#%d:%d#\n",a,b);
                            if(a==1){
                                str[l/2]='0';
                            }
                            else str[l/2]='1';
                        }
                        for(int i=0;i<l;i++)cout<<str[i];
                        printf("\n");
                    }
                    
                }
                    
            }
            
        }
    }
    return 0;
}