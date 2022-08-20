#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[205];
    cin.getline(s, 205);
    int len = strlen(s), bn = 0;
    for(int i = 0; i < len; ++i)
    {
        if(s[i] == ' ')
            bn++;
        else
            bn = 0;
        if(s[i] != ' ' || bn == 1)
            cout << s[i];
    }
    return 0;
}