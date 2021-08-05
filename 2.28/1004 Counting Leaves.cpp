//A1004 Counting Leaves
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int leaf_num[maxn] = {0};

int maxlayer = 0;
void DFS(int root,int layer){  
	if(child[root].size() == 0){
		leaf_num[layer]++;
		if(layer>maxlayer){
			maxlayer = layer;
		}
		return;
	}
	else{
		for(int i=0;i<child[root].size();i++){
			DFS(child[root][i],layer+1);
		}
	}
	
}

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int id,num;
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++){
			int temp;
			scanf("%d",&temp);
			child[id].push_back(temp);
		}
	}
	DFS(1,0);
	for(int i=0;i<=maxlayer;i++){
		printf("%d",leaf_num[i]);
		if(i<=maxlayer-1){
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
