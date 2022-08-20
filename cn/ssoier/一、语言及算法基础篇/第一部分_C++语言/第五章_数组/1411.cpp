#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n < 2)return false;
    for(int i = 2; i <= sqrt(n); ++i)
        if(n % i == 0)
            return false;
    return true;
}
int rev(int n){
    int num = 0;
    for(int a = n; a > 0; a /= 10)
        num = num * 10 + a % 10;
    return num;
}
int main(){
    int m, n;
    cin >> m >> n;
    bool hasShow = false;
    for(int i = m; i <= n; ++i){
        if(isPrime(i) && isPrime(rev(i))){
            if(hasShow == true)
                cout << ',';
            else
                hasShow = true;
            cout << i;
        }
    }
    if(hasShow == false)
        cout << "No";
    return 0;
}