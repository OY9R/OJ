/*坑点 注意 逗号和空格，回车换行*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef stringstream strstm;
#define fi first
#define se second
#define INF 0X3f3f3f3f
#define SZ(x) ((int)(x).size())
#define pb push_back
#define PI acos(-1.0)
#define E 2.718281829459
#define lowbit(x) (x & (-x))
#define DBG(x) cout << (x) <<  << endl;
#define MST(a,b) memset(a,b,sizeof(a));
#define _for(i,a,b) for(int i = (a); i < (b); ++i)
#define _rep(i,a,b) for(int i = (a); i <= (b); ++i)
 
 
int max_num = -INF,min_num = INF,len,idx = 0;
int main(int argc, char const *argv[]) {
	string str; getline(cin,str);
	len = str.length();
	map<int,pair<int,int> > mp;   
	while(str[idx] == ' ' || str[idx] == ',') idx++;
	_rep(i,idx,len){
		if(str[i] == ' ' || str[i] == ',' || i == len){
			if(!mp.count(i-idx) && i != idx) mp[i-idx] = {idx,i};
			if(i!=idx)max_num = max(max_num,i-idx);
			if(i!=idx)min_num = min(min_num,i-idx);
			idx = i+1;
		}
	}
	for(int i = mp[max_num].fi;i< mp[max_num].se;i++) cout << str[i]; cout << endl;
	for(int i = mp[min_num].fi;i< mp[min_num].se;i++)	cout << str[i];cout << endl;
	return 0;
}