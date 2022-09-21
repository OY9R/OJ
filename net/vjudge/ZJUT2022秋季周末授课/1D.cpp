#include <bits/stdc++.h>
typedef long long ll;
int main()
{
	std::string s; std::cin >> s;
	int k; std::cin >> k;
	if(-1 >= s.length()-k)
		std::cout<<s.length()-k<<std::endl;
	for (int i = s.length() - 1; i >= s.length() - k; --i)
		std::cout << s[i];
	return 0;
}
