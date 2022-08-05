#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,x;
    char c;
    cin>>h>>w>>c>>x;
    char c_in=(x==1?c:' ');
    for(int i=0;i<w;++i)cout<<c;
    cout<<endl;
    for(int i=0;i<h-2;++i){
        cout<<c;
        for(int j=0;j<w-2;++j)cout << c_in;
        cout<<c<<endl;
    }
    for(int i=0;i<w;++i)cout << c;
    cout<<endl;
    return 0;
}
