#include<bits/stdc++.h>
using namespace std;
int main(){
    int l, r, ct = 0;
    cin >> l >> r;
    for(int i = l; i <= r; ++i)
        for(int a = i; a > 0; a /= 10)
            if (a % 10 == 2)
                ct++;
    cout << ct << endl;
    return 0;
}