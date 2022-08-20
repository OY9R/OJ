#include<bits/stdc++.h>
using namespace std;
bool hasWord[1005];//hasWord[i]:内存中是否有单词i 
int mem[105], mi = 0;//mem[i]:内存中第i位置的单词 mi:内存中刚刚保存单词的位置 
int ct = 0, m, n, word;//ct:计数 
int main()
{
	memset(mem, -1, sizeof(mem));//mem数组初值为-1，表示该位置没有保存单词。如果保存单词，值为非负整数。 
	cin >> m >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> word;
		if(hasWord[word] == false)//如果word单词不存在 
		{
			hasWord[word] = true;//将word单词设为已经存在 
			mi = (mi + 1) % m;//mi取循环数组中的下一个位置 
			if(mem[mi] >= 0)//如果这个内存中的新位置mi已经有值了 
				hasWord[mem[mi]] = false;//把mi位置保存的单词mem[mi]设为不存在 
			mem[mi] = word;//内存中新位置保存单词word 
			ct++;//这种情况需要到外存查字典 计数加1 
		}
	}
	cout << ct;
	return 0;
}