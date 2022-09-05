#include <iostream>
using namespace std;
string ss[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main() {
    int sum=0;
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++)
        sum=sum+(str[i]-'0');
    string ans=to_string(sum);
    for(int i=0;i<ans.length();i++){
        cout<<ss[ans[i]-'0'];
        if(i!=ans.length()-1)cout<<" ";
    }
    return 0;
}