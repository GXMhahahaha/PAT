//A1053 Path of Equal Weight
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Node{
	int wei;
	vector<int> child;
	
}node[maxn];

bool cmp(int a,int b){
	return node[a].wei > node[b].wei;	
}

int M,N,S;
vector<int> ans;

void DFS(int root,int total_wei){
	
	if(total_wei>S){
		return;
	}
	if(node[root].child.size()==0 && total_wei == S){
		for(int i=0;i<ans.size();i++){
			printf("%d",ans[i]);
			if(i<ans.size()-1){
				printf(" ");
			}
		}
		printf("\n");
		return;
	}
	
	if(node[root].child.size()==0 && total_wei != S){
		
		return;
	}
	
	for(int i=0;i<node[root].child.size();i++){
		
		int poi = node[root].child[i];
		ans.push_back(node[poi].wei);
		DFS(poi,total_wei+node[poi].wei);
		ans.pop_back();	
	}

}


int main(){
	cin>>N>>M>>S;
	
	for(int i=0;i<N;i++){
		scanf("%d",&node[i].wei); 
	}
	for(int i=0;i<M;i++){
		int id,num;
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++){
			int temp;
			scanf("%d",&temp);
			node[id].child.push_back(temp);
		}
		sort(node[id].child.begin(),node[id].child.end(),cmp);
	}
	ans.push_back(node[0].wei);
	DFS(0,node[0].wei);
	
	
	return 0;
} 
