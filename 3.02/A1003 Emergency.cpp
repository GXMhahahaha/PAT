//A1003 Emergency
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x7fffffff

using namespace std;
const int maxn = 550;

bool visited[maxn];
int N,M,source,destination;
int wei[maxn];

struct Edge{
	int id;
	int len;
}; 
int d[maxn];
struct Node{
	int id;
	friend bool operator < (Node a,Node b){
		return d[a.id] > d[b.id];
	}
};

vector<Edge> Adj[maxn];

vector<int> pre[maxn];

void Dij(int source){
	priority_queue <Node> q;
	d[source] = 0;
	//visited[source] = 1;
	Node node;
	node.id = source;
	q.push(node);
	
	while(!q.empty()){
		Node p = q.top();
		q.pop();
		if(visited[p.id] == true){                //这里很重要，之前都写错了 
			continue;
		}
		visited[p.id] = 1;
			
		for(int i=0;i<Adj[p.id].size();i++){
			int vex_id = Adj[p.id][i].id;
			if(visited[vex_id] == 0){
				Node temp;
				temp.id = vex_id;
				q.push(temp);
				
				if(d[vex_id] > d[p.id] + Adj[p.id][i].len){
					d[vex_id] = d[p.id] + Adj[p.id][i].len;
					pre[vex_id].clear();
					pre[vex_id].push_back(p.id);
				}
				else if(d[vex_id] == d[p.id] + Adj[p.id][i].len){
					pre[vex_id].push_back(p.id);
				}
				
			}
				
		}
				
	}

}

int total = 0;
void Print_Path(int s,int d,int teams,int &maxteams){
	if(s == d){
		total++;
		teams+=wei[d];
		if(teams > maxteams){
			maxteams = teams;
		}
		return;
	}
	
	for(int i=0;i<pre[d].size();i++){
		
		Print_Path(s,pre[d][i],teams+wei[d],maxteams);
	}
	

}

int main(){
	cin>>N>>M>>source>>destination;
	for(int i=0;i<N;i++){
		scanf("%d",&wei[i]);
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
	
	fill(d,d+maxn,INF);
	Dij(source);
	int maxteams = -1;
		
	Print_Path(source,destination,0,maxteams);
	cout<<total<<" "<<maxteams<<endl;
	
	
	return 0;
}
