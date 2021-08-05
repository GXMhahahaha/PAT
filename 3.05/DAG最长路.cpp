//DAG�·
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 100;
int N,M;
struct Node{
	int id;
	int indegree = 0;
	int outdegree = 0;
}node[maxn];

struct Edge{
	int id;
	int len;
};

vector<Edge> Adj[maxn];
int Find_source(){
	for(int i=0;i<N;i++){
		if(node[i].indegree == 0){
			return i;
		}
	}
}

int Find_des(){
	for(int i=0;i<N;i++){
		if(node[i].outdegree == 0){
			return i;
		}
	}
}

int dp[maxn] = {0};
vector<int> nextp[maxn];

int DP(int u){
	if(dp[u] > 0){
		return dp[u];
	}
	
	for(int i=0;i<Adj[u].size();i++){
		int v = Adj[u][i].id;
		int len = Adj[u][i].len;
		int newdp = DP(v) + len;
		if(dp[u] < newdp){
			dp[u] = newdp;
			nextp[u].clear();
			nextp[u].push_back(v);
			
		}
		else if(dp[u] == newdp){
			nextp[u].push_back(v);
		}
		
		
		dp[u] = max(dp[u],DP(v) + len);
		
	}
	
	return dp[u];
	
}

vector<int> path;

void Traverse(int sou,int des){
	if(sou == des){
		path.push_back(sou);
		for(int i=0;i<path.size();i++){
			printf("%d ",path[i]);
		}
		cout<<endl;
		path.pop_back();
		return;
	}
	
	path.push_back(sou);
	for(int i=0;i<nextp[sou].size();i++){
		Traverse(nextp[sou][i],des);
	}
	path.pop_back();
	
}

int main(){
	
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,len;
		cin>>a>>b>>len;
		node[a].outdegree++;
		node[b].indegree++;
		Edge edge;
		edge.id = b;
		edge.len = len;
		Adj[a].push_back(edge);
	}
	
	int sou = Find_source();
	int des = Find_des();
	cout<<DP(sou)<<endl;
	Traverse(sou,des);
	
	return 0;
} 

