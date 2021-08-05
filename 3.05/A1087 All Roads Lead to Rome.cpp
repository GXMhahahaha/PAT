//A1087 All Roads Lead to Rome
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int N,K;
const int maxn = 250;
string start_city;
struct City{
	string name;
	int id;
	int hapiness = 0;
}city[maxn];
map<string,int> mp;
struct Edge{
	int id;
	int cost;
};
vector<Edge> Adj[maxn];

int d[maxn];
bool visited[maxn] = {0};
struct Node{
	int id;
	int cost;
	friend bool operator < (Node a,Node b){
		return a.cost > b.cost;
	}
};
vector<int> pre[maxn];

void Dij(int st){
	fill(d,d+maxn,INF);
	d[st] = 0;
	Node node;
	node.id = st;
	node.cost = d[st];
	priority_queue<Node> q;
	q.push(node);
	
	while(!q.empty()){
		node = q.top();
		int u = node.id;
		q.pop();
		if(visited[u]){
			continue;
		}
		visited[u] = 1;
		
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].id;
			int cost = Adj[u][i].cost;
			if(d[v] > d[u] + cost ){
				pre[v].clear();
				pre[v].push_back(u);
				d[v] = d[u] + cost;
				node.id = v;
				node.cost = d[v];
				q.push(node);
			}
			else if(d[v] == d[u] + cost){
				pre[v].push_back(u);
			}
		}	
	} 
}

vector<int> temp_path,path;
int ans_hap = -1;
double ans_aver = -1;
int rout_num = 0;

void DFS(int sou,int des,int hap,int num){
	if(sou == des){
		rout_num++;
		temp_path.push_back(des);
		hap+=city[des].hapiness;
		if(hap > ans_hap){
			path = temp_path;
			ans_hap = hap;
			ans_aver = (hap*1.0)/num;
		}
		else if(hap == ans_hap){
			int temp_aver = (hap*1.0)/num;
			if(temp_aver > ans_aver){
				path = temp_path;
				ans_aver = temp_aver;
			}
		}
		temp_path.pop_back();
	}
	
	temp_path.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		DFS(sou,pre[des][i],hap+city[des].hapiness,num+1);
	}
	temp_path.pop_back();
	
}



int main(){
	cin>>N>>K>>start_city;
	mp[start_city] = 0;
	city[0].id = 0;
	city[0].name = start_city;
	city[0].hapiness = 0;
	int start_id = 0,end_id = -1;
	
	for(int i=1;i<N;i++){
		string na;
		int hap;
		cin>>na>>hap;
		if(na == "ROM"){
			end_id = i;
		}
		city[i].name = na;
		city[i].id = i;
		city[i].hapiness = hap;
		mp[na] = i;
		
	}
	
	for(int i=0;i<K;i++){
		string c1,c2;
		int co;
		cin>>c1>>c2>>co;
		int c1_id = mp[c1];
		int c2_id = mp[c2];
		Edge edge;
		edge.id = c2_id;
		edge.cost = co;
		Adj[c1_id].push_back(edge);
		edge.id = c1_id;
		Adj[c2_id].push_back(edge);
	}
	Dij(start_id);
	DFS(start_id,end_id,0,0);
	printf("%d %d %d %d\n",rout_num,d[end_id],ans_hap,(int)ans_aver);
	
	for(int i=path.size()-1;i>=0;i--){
		cout<<city[path[i]].name;
		if(i>=1){
			cout<<"->";
		}
	}
	cout<<endl;

	return 0;
}
