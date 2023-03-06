#include <bits/stdc++.h>
using namespace std;
const int MAXI = 26 * 26 * 26 * 26 + 10;
bool h[MAXI];
int start = 1;
// int Work1(string s, int index){
//     for (int i = 0; i < s.length(); i++){
//         if (i + index - 1 >= s.length())break;
//         string cur = s.substr(i, index);
//         int solo = 0;
//         for (int m = 0; m < cur.length(); m++) 
//             solo = solo * 26 + (cur[m] - 'a' + 1);
//         h[solo] = 1;
//     }
//     for (int i = start; i <= start * 26; i++)
//         if (!h[i])return i;
//     return -1;
// }
int Work(string s, int index){
    int i = 0,solo = 0,m = pow(26,index);
    memset(h,0,m+10);
    for (; i < index - 1; i++)
	    solo = solo * 26 + s[i] - 'a';
    for (; s[i]; i++) 
        h[solo = (solo * 26 + s[i] - 'a') % m] = 1;
    for (i = 0; i < m; i++)
        if (!h[i]) return i;
    return -1;
}
// string Onion(int solo){
//     string ss = "";
//     int c;
//     while (solo > 0){
//         c = ((solo - 1) % 26) + 1;
//         solo = (solo - 1) / 26;
//         ss = (char)(c + 'a' - 1) + ss;
//     }
//     return ss;
// }
string Onion(int solo,int len){
    string ss = "";
    for(int j = 0; j < len; ss = char(solo % 26 + 'a') + ss, solo /= 26, j++);
    return ss;
}
void Calc(string curStr){
    memset(h, 0, sizeof(h));
    int ans;
    start = 1;
    for (int i = 1; i <= 6; i++){
        if (start == 0) start = 26;
        else start *= 26;
        ans = Work(curStr, i);
        if (ans != -1){
            cout << Onion(ans, i) << endl;
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    string the;
    while (cin >> the)Calc(the);
    return 0;
}