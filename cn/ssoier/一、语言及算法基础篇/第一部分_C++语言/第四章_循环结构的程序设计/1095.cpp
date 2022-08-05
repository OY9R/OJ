#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ct = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i)
        for(int j = i; j > 0; j /= 10)
            if(j % 10 == 1)
                ct++;
    cout << ct << endl;
    return 0;
}