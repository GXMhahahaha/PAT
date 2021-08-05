//PAT A1003 一定要注意这道题用的是无向边！！！！！！
 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int maxsize = 510;

int vexnum,edgenum;
int start,last;
int res_team[maxsize];
int d[maxsize];
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
vector<int> pre[maxsize];

void Dij(){
	fill(d,d+vexnum,INF);
	visited[start] = true;
	d[start] = 0;
	Min_dis node_start;
	node_start.dis = 0;
	node_start.id = start;
	q.push(node_start);
	
	while(!q.empty()){
		Min_dis node;
		node = q.top();
		q.pop();
		
		int u = node.id;
		
		for(int j=0;j<Adj[u].size();j++){
			int v = Adj[u][j].id;
			int wei = Adj[u][j].weight;
			
			if(visited[v]==0 && d[v] > d[u] + wei){
				d[v] = d[u] + wei;
				Min_dis temp;
				temp.id = v;
				temp.dis = d[v];
				q.push(temp);
				
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if(d[v] == d[u] + wei){
								
				pre[v].push_back(u);
			}
		} 
	}
	
	
	
}
//int num=0,max_res=-1;

void find(int v,int add,int& num,int& max_res){                       //测试一下全部带入 
																	  //对于想要改变的全局变量可以使用引用的形式，底层函数结束之后，会把结果
																	  //带回到上层来 
	
	add+=res_team[v];
	
	if(start == v){
		
		if(add > max_res){
			max_res = add;
		}
		num++;
		return;
	}
	
	for(int i=0;i<pre[v].size();i++){
		int u = pre[v][i];
		find(u,add,num,max_res);
	}
	
}

int main(){

	cin>>vexnum>>edgenum>>start>>last;
	
	for(int i=0;i<vexnum;i++){
		scanf("%d",&res_team[i]);
	}
	
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
	
	Dij();
	int num=0,max_res=-1;
	find(last,0,num,max_res);
	cout<<num<<" "<<max_res;
	
	return 0;
}
