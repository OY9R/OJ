#include<bits/stdc++.h>
using namespace std;
#define N 205
void setLen(int a[], int i)
{
    while(a[i] == 0 && i > 1)
        i--;
    a[0] = i;
}
void toNum(char s[], int a[])
{
    a[0] = strlen(s);
    for(int i = 1; i <= a[0]; ++i)
        a[i] = s[a[0] - i] - '0';
    setLen(a, a[0]);
}
void showNum(int a[])
{
    for(int i = a[0]; i >= 1; --i)
        cout << a[i];
    cout << endl;
}
void Add(int a[], int b[], int r[])
{
    int c = 0, i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        r[i] = a[i] + b[i] + c;
        c = r[i] / 10;
        r[i] %= 10;
    }
    r[i] = c;
    setLen(r, i);
}
int main()
{
    char s[N];
    int a[N] = {}, b[N] = {}, r[N] = {};
    cin >> s;
    toNum(s, a);
    cin >> s;
    toNum(s, b);
    Add(a, b, r);
    showNum(r);
    return 0;
}