#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s[105], a;
    int n = 0;
    while (cin >> a) 
        s[++ n] = a;
    for (int i = 1; i < n; i ++)
        for (int j = 1; j <= n - i; j ++)
            if (s[j] > s[j + 1])
                swap(s[j], s[j + 1]);
    n = unique(s + 1, s + 1 + n) - (s + 1);
    for (int i = 1; i <= n; i ++)
        cout << s[i] << endl;
    //getchar();getchar();
    return 0;
}