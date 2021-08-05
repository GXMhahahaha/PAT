//A1068 Find More Coins
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int arr[maxn];
bool cmp(int a,int b){
	return a>b;
}
int dp[maxn] = {0};
bool choice[maxn][110];
bool flag[maxn] = {0};


int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr+1,arr+1+N,cmp);
	for(int i=1;i<=N;i++){
		for(int v=M;v>=arr[i];v--){
			if(dp[v] > dp[v-arr[i]] + arr[i]){
				choice[i][v] = 0;
			}
			else{
				dp[v] = dp[v-arr[i]] + arr[i];
				choice[i][v] = 1;
			}
				
		}
	}
	
	if(dp[M] != M){
		cout<<"No Solution"<<endl;
	}
	else{
		int num = 0;
		int v = M;
		for(int i=N;i>=1;i--){
			if(choice[i][v] == 1){
				flag[i] = 1;
				num++;
				v-=arr[i];
			}
		}
		
		for(int i=N;i>=1;i--){
			if(flag[i] == 1){
				printf("%d",arr[i]);
				num--;
				if(num>0){
					printf(" ");
				}
			}
		}
		cout<<endl;
		
	}
	cout<<endl;
	for(int i=1;i<=N;i++){
		for(int v=0;v<=M;v++){
			printf("%d ",choice[i][v]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
