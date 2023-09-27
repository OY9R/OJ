#include<cstdio>
const int N=6e3+1;
int n,ori,A[N],L[N][N],M[N][N];
signed main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&A[i]);++A[i];
		for (int j=1;j<=n;++j){
			L[i][j]=L[i-1][j]+(A[i]<j);
			M[i][j]=M[i-1][j]+(A[i]>j);
		}//递推求两个数组。
		ori+=M[i][A[i]];
		//计算逆序对。
	}
    if(ori == 0){
        printf("0");
        return 0;
    }
	int ans=ori,ansk=0;
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			int p=ori-M[i-1][A[i]]-M[j-1][A[j]]-L[j-1][A[i]]+L[i][A[i]]
			         +M[i-1][A[j]]+M[j-1][A[i]]+L[j-1][A[j]]-L[i][A[j]];
			//计算：减掉原来的，加上现在的。
			if (ans>p) ans=p,ansk=1;
			else if (ans==p) ++ansk;
		}
	}
	printf("%d",ans+1);
	return 0;
}