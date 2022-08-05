#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << n << '=';
    bool isFirst = true;
    while(n > 1)
        for(int i = 2; i <= n; ++i)
            if(n % i == 0){
                if(isFirst) isFirst = false;
                else cout << '*'; 
                cout << i;
                n /= i;
                break;
            }
    return 0; 
}