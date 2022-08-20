#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
int main()
{
    cin >> s;
    t=s;
    reverse(t.begin(),t.end());
    if(s==t)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}