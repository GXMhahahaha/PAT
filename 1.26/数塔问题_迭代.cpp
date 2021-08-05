//动态规划 数塔问题 迭代 
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

int Find(int layer){
	for(int i=1;i<=layer;i++){
		dp[layer][i] = f[layer][i];
	} 
	for(int i=layer-1;i>=1;i--){
		for(int j=1;j<=layer;j++){
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];h

		}
	
	}
	return dp[1][1];
} 

int main(){
	cin>>L;
	Init(L);
	fill(dp[0],dp[0]+maxn*maxn,-1);
	

	cout<<Find(L);
	
	return 0;
} 
