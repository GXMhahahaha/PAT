#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff

const int maxsize = 510;
int vexnum,edgenum;
int d[maxsize];
int visited[maxsize] = {0};

struct Edge{
	int vex;
	int dis;
};

struct MIN_dis{
	int vex;
	int dis;
	friend bool operator < (MIN_dis a,MIN_dis b){
		return a.dis > b.dis;
	}
};

vector<Edge> Adj[maxsize];
priority_queue<MIN_dis> q;
vector<int> pre[maxsize];

void Dij(int start){
	fill(d,d+vexnum,INF);
	d[start] = 0;
	visited[start] = true;
	
	MIN_dis temp;
	temp.vex = start;
	temp.dis = 0;
	q.push(temp);
	
	for(int i=0;i<vexnum;i++){
		if(q.empty()) 
			return;
		
		MIN_dis top_node;
		
		top_node = q.top();
		int u = top_node.vex;
		visited[u] = true;
		q.pop();	

		for(int j=0;j<Adj[u].size();j++){
			int v = Adj[u][j].vex;
			if(visited[v] == false && d[v] > d[u] + Adj[u][j].dis){
				d[v] = d[u] + Adj[u][j].dis;
				
				MIN_dis temp;
				temp.vex = v;
				temp.dis = d[v];
				q.push(temp);
				
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if(d[v] == d[u] + Adj[u][j].dis){							//这里的条件不能有visited[v] == true 
				pre[v].push_back(u);
			}
		}
		
	}
	
	
}

vector<int> road;


void rout(int start,int end){
	if(start == end){
		road.push_back(start);
	
		for(int i=road.size()-1;i>=0;i--){
			printf("%d ",road[i]);
		}
		printf("\n");
		road.pop_back();								//只能挨个弹出！！！ 
		return;
	}
	
	for(int i=0;i<pre[end].size();i++){
		road.push_back(end);
		rout(start,pre[end][i]);
		road.pop_back();
	}
	
}
int main(){
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
		int head;
		Edge edge;
		scanf("%d %d %d",&head,&edge.vex,&edge.dis);
		Adj[head].push_back(edge);
	}
	int start,end;
	scanf("%d %d",&start,&end);
	
	Dij(start);
	
	printf("%d\n",d[end]);
	rout(start,end);
//	for(int i=0;i<vexnum;i++){
//		printf("%d ",d[i]);
//	}
	
	return 0;
} 
