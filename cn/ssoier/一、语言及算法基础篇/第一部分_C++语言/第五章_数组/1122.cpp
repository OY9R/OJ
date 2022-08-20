#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool isFound = false;//是否找到鞍点
    int a[6][6];
    for(int i = 1; i <= 5; ++i)
    	for(int j = 1; j <= 5; ++j)
    		cin>>a[i][j];
	for(int i = 1; i <= 5; ++i){
		int m_j = 1;
		for(int j = 1; j <= 5; ++j)
			if(a[i][j] > a[i][m_j])
				m_j = j;
		
		bool isAndian = true;
		for(int k = 1; k <= 5; ++k)
			if(a[k][m_j] < a[i][m_j]){
				isAndian = false;
				break;
			}
		if(isAndian)
		{
			cout<<i<<' '<<m_j<<' '<<a[i][m_j]<<endl;
			isFound = true;
			break;
		}
	}
	if(isFound == false)
		cout<<"not found"<<endl;
    return 0;
}