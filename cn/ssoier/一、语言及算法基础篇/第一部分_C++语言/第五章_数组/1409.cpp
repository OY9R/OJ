#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n < 2)return false;
    for(int i = 2; i <= sqrt(n); ++i)
    	if(n % i == 0)return false;
    return true;
}
int main(){
    int ct = 0, x, y;
    cin >> x >> y;
    if(x > y)swap(x, y);
    for(int i = x; i <= y; ++i)
        if(isPrime(i))ct++;
    cout << ct;
    return 0; 
}