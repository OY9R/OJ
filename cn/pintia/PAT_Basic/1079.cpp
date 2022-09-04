#include "bits/stdc++.h"
#define ll long long
char a[1010],b[1010];
using namespace std;
bool check(char *s){
    int len=strlen(s)-1;
    for(int z=0;z<=len;z++,len--)
    	if(s[z]!=s[len]) return false;
    return true;
}
int main(){
    cin>>a;
    for(int z=0;z<10;z++){
        if(check(a)) {
            cout<<a<<" is a palindromic number."<<endl;
            break;
        }
        strcpy(b,a);
        reverse(b,b+strlen(b));
        cout<<a<<" + "<<b<<" = "; 
        int f=0,z1;
        for(z1=0;z1<strlen(a);z1++){
            a[z1]+=b[z1]+f-48;
            f=0;
            if((a[z1]-48)>=10)
            	a[z1]-=(++f?10:0);
        }
        if(f)
        	a[z1++]=49;
        a[z1]='\0';
        reverse(a,a+z1);
        cout<<a<<endl;
    }
    if(!check(a)) cout<<"Not found in 10 iterations."<<endl;
    return 0;
}