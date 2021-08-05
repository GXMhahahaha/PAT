//A1068 Find More Coins »ØËÝ·¨
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,M;
const int maxn = 10010;
const int maxm = 110;
int arr[maxn];

bool choice[maxn] = {0};
bool flag = 0;
void DFS(int index,int total){
	if(flag==1){
		return;
	}
	if(index > N-1){
		return;
	}
	if(total > M){
		return;
	}
	if(total == M){
		int num = 0;
		for(int i=0;i<N;i++){
			if(choice[i]){
				num++;
			}
		}
		for(int i=0;i<N;i++){
			if(choice[i]){
				printf("%d",arr[i]);
				num--;
				if(num>0){
					printf(" ");
				}
			}
		}
		printf("\n");
		flag = 1;
		return;
		
	}
	
	choice[index] = 1;
	DFS(index+1,total+arr[index]);
	choice[index] = 0;
	DFS(index+1,total);
}


int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	DFS(0,0);
	
	return 0;
}
