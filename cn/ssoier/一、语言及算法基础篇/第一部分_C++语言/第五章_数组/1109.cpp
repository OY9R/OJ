#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    bool lightOn;
    cin >> n >> m;
    cout << 1;
    for(int i = 2; i <= n; i++){
        lightOn = true;
        for(int j = 1; j <= m && j <= i; j++)
            if(i % j == 0)
                lightOn = !lightOn;
        if(lightOn == false)
            cout << ',' << i;
    }
    return 0;
}