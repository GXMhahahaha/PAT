//A1045 Favorite Color Stripe  最长公共子列解法 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxl1 = 220;
const int maxl2 = 10010;

int A[maxl1],B[maxl2];
int dp[maxl1][maxl2];

int main(){
	int color_num;
	cin>>color_num;
	int len1;
	cin>>len1;
	for(int i=1;i<=len1;i++){
		scanf("%d",&A[i]);
	}
	int len2;
	cin>>len2;
	for(int i=1;i<=len2;i++){
		scanf("%d",&B[i]);
	}
	
	for(int i=0;i<=len1;i++){
		dp[i][0] = 0;
	}
	
	for(int i=0;i<=len2;i++){
		dp[0][i] = 0;
	}
	
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(A[i] != B[j]){
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j])+1;
			}
		}
	}
	
	cout<<dp[len1][len2]<<endl;
	return 0;
}

 
