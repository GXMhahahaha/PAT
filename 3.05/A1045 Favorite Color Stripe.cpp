//A1045 Favorite Color Stripe 最长不下降子列方法 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 220;
int HashT[maxn];
const int maxlen = 10010;
int arr[maxlen];
int dp[maxlen];
int main(){
	fill(HashT,HashT+maxn,-1);
	fill(dp,dp+maxlen,1);
	
	int color_num;
	cin>>color_num;
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int color;
		scanf("%d",&color);
		HashT[color] = i;
	}
	int N;
	cin>>N;
	int real_len = 0;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		if(HashT[temp] != -1){
			arr[real_len++] = HashT[temp];
		}
	}
	
	for(int i=1;i<real_len;i++){
		for(int j=0;j<i;j++){
			if(arr[j] <= arr[i]){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
	}
	int max_len = -1;
	for(int i=0;i<real_len;i++){
		if(dp[i] > max_len){
			max_len = dp[i];
		}
	}
	cout<<max_len<<endl;
	return 0;
}
