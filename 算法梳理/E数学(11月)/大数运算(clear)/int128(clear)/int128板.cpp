//Project...
//1 C++/”Ô—‘/C++20
//2 C++/≥£πÊ/SDLºÏ≤È/∑Ò(sdl/)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
__int128 read()
{
    char ch = 0; __int128 x = 0, f = 1;
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
    return x * f;
}
void print(__int128 x)
{
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9)print(x / 10);
    putchar(int(x % (10)) + '0');
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    __int128 x;
    while (x = read())
    {
        print(x);
        putchar('\n');
    }
    return 0;
}
