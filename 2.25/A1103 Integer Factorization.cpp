//A1103 Integer Factorization
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,K,P;
vector<int> temp,ans;

int maxfac_sum = -1;
void DFS(int index,int sum,int nowK,int fac_sum){
	if(sum == N && nowK == K){
		if(fac_sum > maxfac_sum){
			ans = temp;
			maxfac_sum = fac_sum;
		}
		return;
	}
	if(sum>N||nowK>K)	return;
	
	if(index>0){
		temp.push_back(index);
		DFS(index,sum+pow(index*1.0,P),nowK+1,fac_sum+index);
		temp.pop_back();
		DFS(index-1,sum,nowK,fac_sum);
	}
	
}


int main(){

	cin>>N>>K>>P;
	int M = 0;
	for(int i=1;i<=N;i++){
		if((int)pow(i*1.0,P) >= N){
			M = i;
			break;
		}
	}
	DFS(M,0,0,0);
	if(ans.size()==0){
		printf("Impossible\n");
		return 0;
	}
	printf("%d = ",N);
	for(int i=0;i<ans.size();i++){
		printf("%d^%d",ans[i],P);
		if(i<ans.size()-1){
			printf(" + ");
		}
	}
	printf("\n");
	return 0;
}
