//A1021 Deepest Root
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N;
const int maxn = 10010;
vector<int> Adj[maxn];
bool visited[maxn] = {0};

set<int> ans;
set<int> final_ans;
int maxdepth = -1;
void DFS_traverse(int u,int depth){
	visited[u] = 1;
	for(int i=0;i<Adj[u].size();i++){
		int graph_num = Adj[u][i];
		int next_num = 0;
		if(visited[graph_num] == 0){
			next_num++;
			DFS_traverse(graph_num,depth+1);
		}
		if(next_num == 0 && depth > maxdepth){
			maxdepth = depth;
			ans.clear();
			ans.insert(u);
		}
		else if(next_num == 0 && depth == maxdepth){
			ans.insert(u);
		}
	}
	
	
	
}

int DFS(){
	int block = 0;
	for(int i=1;i<=N;i++){
		if(visited[i] == 0){
			DFS_traverse(i,0);
			block++;
		}
		
	}
	return block;
}


int main(){
	cin>>N;
	if(N==1){
		printf("1\n");
		return 0;
	}
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int block_num = DFS();
	
	if(block_num > 1){
		printf("Error: %d components\n",block_num);
	}
	else{
		final_ans = ans;
		ans.clear();
		maxdepth = -1;
		fill(visited,visited+maxn,0);
		
		DFS_traverse(*final_ans.begin(),0);
		
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			final_ans.insert(*it);
		}
		for(set<int>::iterator it=final_ans.begin();it!=final_ans.end();it++){
			printf("%d\n",*it);
		}
			
	}
	

	return 0;
} 
