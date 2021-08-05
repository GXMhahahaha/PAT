//A1030 Travel Plan
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int N,M;
const int maxn = 10;
struct Edge{
	int len;
	int cost;
};


Edge G[maxn][maxn];
bool visited[maxn] = {0};
int d[maxn];

struct Node{
	int id;
	friend bool operator < (Node a,Node b){
		return d[a.id] > d[b.id];
	}
};

vector<int> pre[maxn];

void Dij(int source){
	d[source] = 0;
	priority_queue<Node> q;
	Node node;
	node.id = source;
	q.push(node);
	
	while(!q.empty()){
		node = q.top();
		q.pop();
		int u = node.id;
		if(visited[u] == 1){
			continue;
		}
		visited[u] = 1;
		
		for(int v=0;v<maxn;v++){
			int length = G[u][v].len;
			if(!visited[v] && length != INF){
				
				if(d[v] > d[u] + length){
					d[v] = d[u] + length;
					pre[v].clear();
					pre[v].push_back(u);
					node.id = v;
					q.push(node);
				}
				else if(d[v] == d[u] + length){
					pre[v].push_back(u);
				}
			}
		}
	}
		
}

vector<int> temp_path,path;
int min_cost = INF;
void Traverse(int s,int d,int cost){

	if(s == d){
		temp_path.push_back(d);
		if(cost < min_cost){
			path = temp_path;
			min_cost = cost;
		}
		temp_path.pop_back();
		return;
	}
	for(int i=0;i<pre[d].size();i++){
		temp_path.push_back(d);
		int newsource = pre[d][i];
		Traverse(s,newsource,cost+G[d][newsource].cost);
		temp_path.pop_back();
	}
	
}


int main(){
	fill(d,d+maxn,INF);
	Edge edge;
	edge.cost = INF;
	edge.len = INF;
	fill(G[0],G[0]+maxn*maxn,edge);
	edge.cost = 0;
	edge.len = 0;
	for(int i=0;i<maxn;i++){
		G[i][i] = edge;
	}
	int S,D;
	cin>>N>>M>>S>>D;
	for(int i=0;i<M;i++){
		int a,b,l,c;
		scanf("%d %d %d %d",&a,&b,&l,&c);
		Edge edge;
		edge.len = l;
		edge.cost = c;
		G[a][b] = edge;
		G[b][a] = edge;

	}
	Dij(S);
	Traverse(S,D,0);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}
	printf("%d %d\n",d[D],min_cost);
	return 0;
} 
