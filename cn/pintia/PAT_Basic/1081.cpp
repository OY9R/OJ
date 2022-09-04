#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        string str;
        getline(cin,str);
        if(str.length()<6){
            printf("Your password is tai duan le.\n");
            continue;
        }
        int n=0,w=0,flag=0;
        for(int i=0;i<str.length();i++){
            if(str[i]>='0'&&str[i]<='9')
                n=1;
            else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
                w=1;
            else if(str[i]=='.')
                ;
            else
                flag=1;
        }
        if(flag==1)
            printf("Your password is tai luan le.\n");
        else if(n==1&&w==0)
            printf("Your password needs zi mu.\n");
        else if(n==0&&w==1)
            printf("Your password needs shu zi.\n");
        else
            printf("Your password is wan mei.\n");
    }
    return 0;
} 