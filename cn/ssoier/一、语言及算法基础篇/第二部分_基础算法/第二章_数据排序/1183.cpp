#include<bits/stdc++.h>
using namespace std;
#define N 105
struct Peo{
	char id[10];
	int age, num;
};
bool cmp(Peo a, Peo b){
    if(a.age < 60 && b.age < 60 || a.age == b.age)
        return a.num < b.num;
    else
        return a.age > b.age;
}
int main(){
	int n;
	cin >> n;
	Peo a[N];
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i].id >> a[i].age;
	    a[i].num = i;
	}
        stable_sort(a+1, a+1+n, cmp);
	for(int i = 1; i <= n; ++i)
		cout << a[i].id << endl;
	return 0;
}