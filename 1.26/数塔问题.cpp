//动态规划 数塔问题
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
int f[maxn][maxn];
int dp[maxn][maxn];
int L;
void Init(int layer){
	for(int i=1;i<=layer;i++){
		for(int j=1;j<=i;j++){
			cin>>f[i][j];
		}
		getchar();
	}
}

//int Find1(int u,int v){							这么写太麻烦了 
//	if(u == L){
//		dp[u][v] = f[u][v];
//		return f[u][v]; 
//	}
//	
//	if(dp[u+1][v] != -1 && dp[u+1][v+1] != -1)
//		return max(dp[u+1][v],dp[u+1][v+1]) + f[u][v];
//		
//	if(dp[u+1][v] != -1 && dp[u+1][v+1] == -1)
//		return max(dp[u+1][v],Find(u+1,v+1)) + f[u][v];
//	
//	if(dp[u+1][v] == -1 && dp[u+1][v+1] != -1)
//		return max(Find(u+1,v),dp[u+1][v+1])+ f[u][v];
//	
//	return max(Find(u+1,v),Find(u+1,v+1)) + f[u][v];
//	
//	
//}

int Find2(int u,int v){
	if(u == L){
		dp[u][v] = f[u][v];
		return f[u][v]; 
	}
	
	if(dp[u][v]!=-1) return dp[u][v];
	else {
		dp[u][v] = max(Find2(u+1,v),Find2(u+1,v+1)) + f[u][v];
		return dp[u][v];
	}
} 

int main(){
	cin>>L;
	Init(L);
	fill(dp[0],dp[0]+maxn*maxn,-1);
	
//	for(int i=0;i<maxn;i++){
//		cout<<dp[i][i]<<" ";
//	}
	cout<<Find2(1,1);
	
	return 0;
} 
