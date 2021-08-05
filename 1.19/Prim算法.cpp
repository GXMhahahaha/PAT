//Prim算法
 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int maxsize = 510;

int vexnum,edgenum;

int d[maxsize];  //与Dij不同，此处表示的是与连通集合的距离 
bool visited[maxsize] = {0};

struct Edge{
	int id;
	int weight;
};

struct Min_dis{
	int id;
	int dis;
	friend bool operator < (Min_dis a,Min_dis b){
		return a.dis > b.dis;
	}
};

vector<Edge> Adj[maxsize];
priority_queue<Min_dis> q;

int Prim(int start){
	int num = 0;
	fill(d,d+vexnum,INF);
	d[start] = 0;
	Min_dis node_start;
	node_start.dis = 0;
	node_start.id = start;
	q.push(node_start);
	
	while(!q.empty()){
		Min_dis node;
		if(visited[q.top().id] == true){		//前面写的最短路径其实都有点逻辑问题 
			q.pop();
			continue;
		}

		node = q.top();
		int u = node.id;
		visited[u] = true;
		num+=d[u];
		q.pop();
		
		
		for(int j=0;j<Adj[u].size();j++){
			int v = Adj[u][j].id;
			int wei = Adj[u][j].weight;
			
			if(visited[v]==0 && d[v] > wei){
				d[v] = wei;
				Min_dis temp;
				temp.id = v;
				temp.dis = d[v];
				q.push(temp);
				
			}
	
		} 
	}
	
	return num;
	
}

int main(){

	cin>>vexnum>>edgenum;
	
	for(int i=0;i<edgenum;i++){
		int vex;
		int id;
		int weight;
		Edge edge;
		scanf("%d %d %d",&vex,&id,&weight);
		edge.id = id;
		edge.weight = weight;
		Adj[vex].push_back(edge);
		edge.id = vex;
		Adj[id].push_back(edge);
		
	}
	
	int num = Prim(0);
	
	cout<<num<<endl;
	
	return 0;
}
