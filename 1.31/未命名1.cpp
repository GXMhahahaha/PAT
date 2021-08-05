//0 1背包问题  滚动数组法 
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5, maxv = 1e5;
int w[maxn],c[maxn],dp[maxv]={0};

int n,V;
int main(){
	cin>>n>>V;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	for(int i=0;i<n;i++){
		for(int v=V;v>=w[i];v--){
			dp[v] = max(dp[v-w[i]]+c[i],dp[v]);
		}
	}
	int MAX = -1;
	for(int i=0;i<=V;i++){
		if(dp[i] > MAX){
			MAX = dp[i];
		}
	}
	cout<<MAX;	
	return 0;
}
