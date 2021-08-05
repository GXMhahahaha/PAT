//Prim Ëã·¨
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;
const int maxn = 100;
struct Edge{
	int id;
	int len;
};

vector<Edge> Adj[maxn];

int d[maxn];
bool visited[maxn] = {0};

struct Node{
	int id;
	int wei;
	friend bool operator < (Node a,Node b){
		return a.wei > b.wei;
	}
};
int Prim(){
	fill(d,d+maxn,INF);
	d[0] = 0;
	Node node;
	node.id = 0;
	node.wei = d[0];
	priority_queue<Node> q;
	q.push(node);
	int total = 0;
	while(!q.empty()){
		node = q.top();
		q.pop();
		int u = node.id;
		if(visited[u]){
			continue;
		}
		total+=node.wei;
		visited[u] = 1;
		
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].id;
			int len = Adj[u][i].len;
			if(!visited[v] && d[v] > len){
				d[v] = len;
				node.id = v;
				node.wei = d[v];
				q.push(node);
			}
		
		}
		
	}
	return total;	
}


int main(){
	int N,M;
	cin>>N>>M;
	
	
	for(int i=0;i<M;i++){
		int a,b,len;
		cin>>a>>b>>len;
		Edge edge;
		edge.id = a;
		edge.len = len;
		Adj[b].push_back(edge);
		edge.id = b;
		Adj[a].push_back(edge);
	}
	cout<<Prim()<<endl;
	
	return 0;
}  
