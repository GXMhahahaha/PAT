//A1018 Public Bike Management
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
const int maxn = 550;
int Cmax,N,index,M;
struct Edge{
	int id;
	int len;
};
vector<Edge> Adj[maxn];
int bike_num[maxn];
bool visited[maxn] = {0};
int d[maxn];

struct Node{
	int id;
	int wei;
	friend bool operator < (Node a,Node b){
		return a.wei > b.wei; 
	}
};

vector<int> pre[maxn];
vector<int> path;
vector<int> temp_path;

void Dij(){
	priority_queue<Node> q; 
	d[0] = 0;
	Node node;
	node.id = 0;
	node.wei = 0;
	q.push(node);
	
	while(!q.empty()){
		node = q.top();
		q.pop();
		if(visited[node.id]){
			continue;
		}
		
		int u = node.id;
		visited[u] = 1;
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].id;
			int length = Adj[u][i].len;
			if(!visited[v]){
				node.id = v;
				
				if(d[v] > d[u] + length){
					pre[v].clear();
					pre[v].push_back(u);
					d[v] = d[u] + length;
					node.wei = d[v];
					q.push(node);
                    
				}
				else if(d[v] == d[u]+length){
					pre[v].push_back(u);
				}
				
			}
			
		}

	}
		
}


int minsend = INF,minreturn = INF;
void Search(int sou,int des){
	if(sou == des){
		temp_path.push_back(des);
		int remain = 0;
		int need = 0;
		for(int i=temp_path.size()-1;i>=0;i--){
			int node_id = temp_path[i];
			if(bike_num[node_id] > 0){
				remain+=bike_num[node_id];
			}
			else{
				if(remain > abs(bike_num[node_id])){
					remain-=abs(bike_num[node_id]);
				}
				else{
					need+=abs(bike_num[node_id])-remain;
					remain = 0;
					
				}
			}
		}
		if(need < minsend){
			path = temp_path;
			minsend = need;
			minreturn = remain;
		}
		else if(need == minsend && remain < minreturn){
			path = temp_path;
			minreturn = remain;
		}

		temp_path.pop_back();
		return;
	}
	temp_path.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		Search(sou,pre[des][i]);
	}
	temp_path.pop_back();
}


int main(){
	fill(d,d+maxn,INF);
	cin>>Cmax>>N>>index>>M;
	for(int i=0;i<N;i++){
		scanf("%d",&bike_num[i+1]);
        bike_num[i+1]-=Cmax/2;
	}
	for(int i=0;i<M;i++){
		int a,b,l;
		scanf("%d %d %d",&a,&b,&l);
		Edge edge;
		edge.id = b;
		edge.len = l;
		Adj[a].push_back(edge);
		edge.id = a;
		Adj[b].push_back(edge);
	}
	
	Dij();
	Search(0,index);

	printf("%d ",minsend);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i>0){
			printf("->");
		}
	}
	printf(" %d\n",minreturn);
	return 0;
} 

