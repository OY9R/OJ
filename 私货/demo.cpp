#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> out;
    while(n>0){
        out.push_back(n%8);
        n/=8;
    }
    reverse(out.begin(),out.end());
    for(int i=0;i<out.size();i++)
        cout<<out[i];
    cout<<endl;
    return 0;
}