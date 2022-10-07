#include <bits/stdc++.h>
using namespace std;
int book[10];
void getint128(__int128 &x){
    char c=getchar();
    while(c>='0'&&c<='9'){
        book[c-'0']++;
        x=x*10+(c-'0');
        c=getchar();
    }
}
void putint128(__int128 x){
    if(x>9) putint128(x/10);
    putchar(x%10+'0');
}
bool check(__int128 x){
    while(x){
        book[x%10]--;
        x/=10;
    }
    for(int i=0;i<10;i++)
        if(book[i])
            return false;
    return true;
}
int main() {
    __int128 n=0;
    getint128(n);
   n<<=1;
   if(check(n))cout<<"Yes\n";
   else cout<<"No\n";
    putint128(n);
    return 0;
}
