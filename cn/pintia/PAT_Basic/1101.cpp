#include <bits/stdc++.h>
using namespace std;
string a, b;
int d;
int main(){
    cin>>a>>d;
    b=a.substr(a.size()-d)+a.substr(0,a.size()-d);
    printf("%.2f",stod(b)/stod(a));
    return 0;
}