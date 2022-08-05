#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        if (i % 7 == 0) continue;
        int m = i;
        bool isRelevant = false;
        while(m > 0){
            if (m % 10 == 7){
                isRelevant = true;
                break;
            }
            m /= 10;
        }
        if (isRelevant) continue;
        sum += i * i;
    }
    cout<<sum<<endl;
    return 0;
}