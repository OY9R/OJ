#include <cstdio>
#include <iostream>
using namespace std;
int m[300][300],N,A,B;
int main() {
	scanf("%d%d%d",&N,&A,&B);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(i==j)
				m[i][i]=0;
			else
				m[i][j]=50000;
	for(int i=1; i<=N; i++) {
		int temp;
		scanf("%d",&temp);
		if(i+temp<=N)
			m[i][i+temp]=1;
		if(i-temp>=1)
			m[i][i-temp]=1;
	}
	for(int k=1; k<=N; k++)
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				if(m[i][j]>m[i][k]+m[k][j])
					m[i][j]=m[i][k]+m[k][j];
	printf("%d",m[A][B]<50000 ? m[A][B] : -1);
	return 0;
}