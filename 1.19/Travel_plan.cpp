//PAT A1030 Travel Plan

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

const int maxn = 500;

int dis[maxn][maxn];
int cost[maxn][maxn];
int d[maxn];
bool visited[maxn] = {0};

int vexnum,edgenum,source,destination;


struct Edge{
	int id;
	int min_d;
	friend bool operator < (Edge a,Edge b){
		return a.min_d > b.min_d;
	}
};

priority_queue<Edge> q;

vector<int> temp_path;
vector<int> path;
vector<int> pre[maxn];

void DFS(){
	fill(d,d+vexnum,INF);
	Edge first;
	first.id = source;
	first.min_d = 0;
	q.push(first);
	d[source] = 0;

	while(!q.empty()){
		
		if(visited[q.top().id] == true){                //这里很重要，之前都写错了 
			q.pop();
			continue;
		}
		
		Edge edge;
		edge = q.top();
		q.pop();
		int u = edge.id;
		visited[u] = 1;

		
		for(int v=0;v<vexnum;v++){
			
			if(visited[v] == 0 && dis[u][v] != INF){			//这里是可以的，因为如果某一结点有多条最短路径，那么在确定其中任何一条之前，这个点都不会被访问 
				if(d[v]>dis[u][v]+d[u]){
					d[v] = dis[u][v] + d[u];
					Edge temp;
					temp.id = v;
					temp.min_d = d[v];
					q.push(temp);
					
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[v]==dis[u][v]+d[u]){
					pre[v].push_back(u);
				}				
			}
			

		}
	}
	
	
}

void find(int v,int add_c,int add_d,int& totalcost,int& totaldis){
	
	if(v == source){
		if(add_c < totalcost){
			totalcost = add_c;
			totaldis = add_d;
			temp_path.push_back(v);
			path = temp_path;
			temp_path.clear();
		}
		else{
			temp_path.clear();
		}
		
		return ;
	}
	
	for(int i=0;i<pre[v].size();i++){
		add_c += cost[pre[v][i]][v];
		add_d += dis[pre[v][i]][v];
		temp_path.push_back(v);
		find(pre[v][i],add_c,add_d,totalcost,totaldis);
		add_c -= cost[pre[v][i]][v];									//这里要把上一次循环的结果减去 
		add_d -= dis[pre[v][i]][v];
	}
	
}

int main(){
	
	fill(dis[0],dis[0]+maxn*maxn,INF);									//二元数组的赋值要格外小心 
	
	fill(cost[0],cost[0]+maxn*maxn,INF);
	
	for(int i=0;i<maxn;i++){
		dis[i][i] = 0;
		cost[i][i] = 0;
	}
	
	cin>>vexnum>>edgenum>>source>>destination;
	for(int i=0;i<edgenum;i++){
		int s,d,dis_temp,cos_temp;
		scanf("%d %d %d %d",&s,&d,&dis_temp,&cos_temp);
		dis[s][d] = dis_temp;
		dis[d][s] = dis_temp;
		cost[s][d] = cos_temp;
		cost[d][s] = cos_temp;
	}
		
	DFS();
	int totalcost = INF;
	int totaldis = INF;

	
	
	find(destination,0,0,totalcost,totaldis);
	
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	cout<<totaldis<<" "<<totalcost<<endl;
	
	return 0;
}
 
