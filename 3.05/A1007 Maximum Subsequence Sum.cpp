//A1007 Maximum Subsequence Sum
#include <iostream>
#include <stdio.h>
#define INF 0x7fffffff
#define endl '\n'
using namespace std;
const int maxn = 10010;
int dp[maxn];
int c[maxn];
int N;
int arr[maxn];
int main(){
	cin>>N;
	int num_of_neg = 0;
	
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		arr[i] = temp;
		if(temp < 0){
			num_of_neg++;
		}
	}
	
	if(num_of_neg == N){
		cout<<"0"<<" "<<arr[0]<<" "<<arr[N-1]<<endl;
		return 0;
	}
	
	dp[0] = arr[0];
	c[0] = 0;
	
	for(int i=1;i<N;i++){
		if(dp[i-1] + arr[i] >= arr[i]){
			dp[i] = dp[i-1] + arr[i];
			c[i] = c[i-1];
		}
		else{
			dp[i] = arr[i];
			c[i] = i;
		}
		
	}
	
	int maxsum = -INF,min_i;
	int min_j;
	for(int i=0;i<N;i++){
		if(dp[i] > maxsum){
			maxsum = dp[i];
			min_i = c[i];
			min_j = i;
		}
		else if(dp[i] == maxsum && c[i] < min_i){
			min_i = c[i];
			min_j = i;
		}
	}
	cout<<dp[min_j]<<" "<<arr[min_i]<<" "<<arr[min_j]<<endl;
	return 0;
}
