#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","w",stdout);
    srand(time(NULL));
    // int x=rand()%1000+1,y=rand()%1000+1;
    // cout << x << " " << y;
    int n=10;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<(rand()%2?"Server":"Client")<<' ';
        cout<<rand()%260<<'.'<<rand()%260<<'.'<<rand()%260<<":........."[rand()%10]<<rand()%260<<":::::::::."[rand()%10]<<"0987654321"[rand()%10]<<rand()%100<<endl;
    }
    return 0;
}
//生成名为make