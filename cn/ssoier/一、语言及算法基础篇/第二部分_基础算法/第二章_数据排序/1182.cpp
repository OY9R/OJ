#include <bits/stdc++.h>
using namespace std;
struct Stu
{
    char s[15];
    double h;
    bool operator < (const Stu &b) const{
        if(s[0] == 'm' && b.s[0] == 'm')
            return h < b.h;
        else if(s[0] == 'f' && b.s[0] == 'f')
            return h > b.h;
        else
            return s[0] == 'm';
    }
};
int main(){
    Stu a[45];
    int n;
    cin >> n;
	for(int i = 1; i <= n; ++i)
	    cin >> a[i].s >> a[i].h;
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i)
        cout << fixed << setprecision(2) << a[i].h << ' '; 
	return 0;
}