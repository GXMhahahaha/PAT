//关键路径 其中最后一个点是汇点 
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 0x7fffffff
#define endl "\n"
const int maxn = 1e5;

int vexnum,edgenum;
int indegree[maxn]={0};

struct Edge{
	int v0;
	int cost;
};
vector<Edge> Adj[maxn];
vector<int> _Adj[maxn];

int ve[maxn] = {0};
int vl[maxn];

stack<int> s;

vector<int> next0[maxn];
vector<int> road;

bool Topo(){
	
	queue<int> q;
	for(int i=0;i<vexnum;i++){
		if(indegree[i] == 0){
			q.push(i);
			break;	
		}
	}
	int num = 0;
	while(!q.empty()){
		int u = q.front();
		s.push(u);
		q.pop();
		num++;
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].v0;
			indegree[v]--;
			if(ve[u] + Adj[u][i].cost > ve[v]){
				ve[v] = ve[u] + Adj[u][i].cost;
			}
			if(indegree[v] == 0){
				q.push(v);
			}
		}
		
	}
	
	if(num == vexnum)
		return true;
	else 
		return false;
}



int Critical(){
	int total_len = 0;
	if(!Topo())
		return -1;
	fill(vl,vl+maxn,ve[vexnum-1]);
	while(!s.empty()){
		int u = s.top();
		s.pop();
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].v0;
			if(vl[v] - Adj[u][i].cost < vl[u]){
				vl[u] = vl[v] - Adj[u][i].cost;
			}			
		}

	}
	
	for(int i=0;i<vexnum;i++){
		for(int j=0;j<Adj[i].size();j++){
			int v = Adj[i][j].v0;
			int e = ve[i];
			int l = vl[v] - Adj[i][j].cost;
			if(l == e){
				next0[i].push_back(v); 
			}
		}
	}
	return ve[vexnum-1];
}

void Output(int _start,int _end){
	 if(_start == _end){
		road.push_back(_start);
		for(int j=0;j<road.size();j++){
			if (j<road.size()-1)
				cout<<road[j]<<"->";
			else
				cout<<road[j]<<endl;
		}
		road.pop_back();
		return;
	} 
	
	
	for(int j=0;j<next0[_start].size();j++){
		road.push_back(_start);
		int v = next0[_start][j];
		Output(v,_end);
		road.pop_back();
	}
}

int main(){
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
		int u,_v,c;
		scanf("%d %d %d",&u,&_v,&c);
		indegree[_v]++;
		Edge edge;
		edge.v0 = _v;
		edge.cost = c;
		Adj[u].push_back(edge);
	}
	int len = Critical();
	cout<<len<<endl;
	Output(0,vexnum-1);
	
	return 0;
} 
