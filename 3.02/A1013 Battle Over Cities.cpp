//A1013 Battle Over Cities
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
vector<int> graph[maxn];
int N,M,K;

bool visited[maxn] = {0};

DFS_traverse(int i,int dele){
	visited[i] = 1;
	for(int j=0;j<graph[i].size();j++){
		int gnum = graph[i][j];
		if(visited[gnum]==0 && gnum!=dele){
			DFS_traverse(gnum,dele);
		}
	}
		
}

int DFS(int dele){
	int count = 0;
	for(int i=1;i<=N;i++){
		if(visited[i] == 0 && i!=dele){
			DFS_traverse(i,dele);
			count++;
		}
	}
	return count;
}



int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<K;i++){
		int dele;
		scanf("%d",&dele);
		fill(visited,visited+maxn,0);
		cout<<DFS(dele)-1<<endl;
	}
	
	
	
	return 0;
}
