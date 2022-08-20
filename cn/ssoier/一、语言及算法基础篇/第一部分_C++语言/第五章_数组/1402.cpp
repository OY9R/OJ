#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s_k[105], s_c[1005], st_c;//s_k:密钥字符串 s_c:密文字符串 st_c：标记当前字符是大写还是小写字母。 
	cin >> s_k >> s_c;
	int lc = strlen(s_c), lk = strlen(s_k), n_k[105], n_c;//n_k:密钥字母对应的数字构成的的数组 n_c:当前明文中字母对应的数字(A~Z对应0~25)
	for(int i = 0; i < lk; ++i)//求出n_k数组 
	{
		if(s_k[i] >= 'A' && s_k[i] <= 'Z')
			n_k[i] = s_k[i] - 'A';
		else
			n_k[i] = s_k[i] - 'a';
	}
	for(int i = 0, j = 0; i < lc; ++i, j = (j+1)%lk)//i:s_c的下标 j:n_k的下标
	{
		if(s_c[i] >= 'A' && s_c[i] <= 'Z')
		{
			st_c = 'A';
			n_c = s_c[i] - 'A';
		}
		else
		{
			st_c = 'a';
			n_c = s_c[i] - 'a';
		}
		cout << char((n_c - n_k[j] + 26) % 26 + st_c); 
	}
	return 0;
}