//AndrewÇóÍ¹°ü
#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int ans,n,pt;
int x[N], y[N],arr[3][N],apt[3];
struct node
{
    int x; int y; int num;
    bool operator<(const node& e)const
        {return (x == e.x) ? y < e.y: x < e.x;}
}nod[N];
int comp(int a, int b, int c, int d)//(a->b)>(c->d)(rev+)
{return 1ll * (nod[b].y - nod[a].y) * (nod[d].x - nod[c].x) >=
        1ll * (nod[d].y - nod[c].y) * (nod[b].x - nod[a].x);}
void getconvexhull()            //358
{                               //2 7
    sort(nod + 1, nod + n + 1);//146
    pt = 1; while (pt <= n && nod[1].x == nod[pt].x)arr[1][++apt[1]] = pt++;
    for (; pt <= n; arr[1][++apt[1]] = pt++)while (apt[1] >= 2 &&
        comp(arr[1][apt[1] - 1], pt, arr[1][apt[1] - 1], arr[1][apt[1]]))apt[1]--;
    pt = n; while (pt >= 1 && nod[n].x == nod[pt].x)arr[2][++apt[2]] = pt--;
    for (; pt >= 1; arr[2][++apt[2]] = pt--) while (apt[2] >= 2 &&
        comp(arr[2][apt[2] - 1], pt, arr[2][apt[2] - 1], arr[2][apt[2]]))apt[2]--;
    for (int e = 1; e <= 2; e++)for (int i = 2; i <= apt[e]; i++)arr[0][apt[0]++] = arr[e][i];
}
void solve()
{
    cin >> n; apt[0] = apt[1] = apt[2] = 0;
    for (int i = 1; i <= n; i++)cin >> nod[i].x >> nod[i].y, nod[i].num = i;
    getconvexhull(); n = apt[0]; for (int e = 0; e < 3; e++)apt[e] = e;
    for (int l = 0, r = 0; r <= l + 3; r++)
    {
        int e = r % 3, a = arr[0][apt[(e + 1) % 3]], b = arr[0][apt[(e + 2) % 3]];
        while (!comp(b, a, arr[0][apt[e]], arr[0][(apt[e] + 1) % n]))apt[e] = (apt[e] + 1) % n, l = r;
        while (!comp(arr[0][(apt[e] - 1 + n) % n], arr[0][apt[e]], b, a))apt[e] = (apt[e] - 1 + n) % n, l = r;
    }
    for (int e = 0; e < 3; e++) cout << nod[arr[0][apt[e]]].num << ' ';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;//cin>>t;
    while (t--)solve();
}