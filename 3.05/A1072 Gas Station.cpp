//A1072 Gas Station
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#define INF 0x7fffffff
using namespace std;
const int maxn = 1050;
int N,M,K,Ds;
struct Edge{
	int id;
	int len;
};
vector<Edge> Adj[maxn];

int change(char str[]){
	int ID = 0;
	int i = 0;
	int len = strlen(str);
	while(i<len){
		if(str[i] != 'G'){
			ID = ID*10+str[i]-'0';	
		}
		i++;
	}
	
	if(str[0] == 'G'){
		return N+ID;
	}
	else{
		return ID;
	}
}
bool visited[maxn] = {0};
int d[maxn];

bool flag = 0;
int temp_id;
int real_id;
int temp_dis;
int max_dis = -1;
int real_dis;

void Init(){
	fill(d,d+maxn,INF);
	fill(visited,visited+maxn,0);
}

struct Node{
	int id;
	int wei;
	friend bool operator < (Node a,Node b){
		return a.wei > b.wei;
	}
};


bool Dij(int u){
	d[u] = 0;
	priority_queue<Node> q;
	Node node;
	node.id = u;
	node.wei = 0;
	q.push(node);
	while(!q.empty()){
		node = q.top();
        int u = node.id;
		q.pop();
		if(visited[u]){
			continue;
		}
		visited[u] = 1;
		if(node.wei > Ds){
			return false;
		}
		
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].id;
			int length = Adj[u][i].len;
			if(!visited[v]){
				if(d[v] >= d[u] + length){
					d[v] = d[u] + length;
					node.id = v;
					node.wei = d[v];
					q.push(node);
				}
			}
		}
			
	}
	flag = true;
	return true;	
}

void Judge(int id){
	int min_dis = INF;
	int total_dis = 0;
	for(int i=1;i<=N;i++){
		total_dis+=d[i];
		if(min_dis > d[i]){
			min_dis = d[i];
		}
	}
	if(min_dis > max_dis){
		max_dis = min_dis;
		real_id = id;
		real_dis = total_dis;
	}
	if(min_dis == max_dis){
		if(total_dis < real_dis){
			real_id = id;
			real_dis = total_dis;
		}
	}	
	
}


int main(){
	
	cin>>N>>M>>K>>Ds;
	
	for(int i=0;i<K;i++){
		char str[5];
		scanf("%s",str);
		int a = change(str);
		scanf("%s",str);
		int b = change(str);
		int l;
		scanf("%d",&l);
		Edge edge;
		edge.id = b;
		edge.len = l;
		Adj[a].push_back(edge);
		edge.id = a;
		Adj[b].push_back(edge);
	}
	
	for(int i=1;i<=M;i++){
		Init();
		if(Dij(i+N)){
			Judge(i+N);
		}
	}
	
	if(flag){
		printf("G%d\n",real_id-N);
		double aver_dis = real_dis*1.0/N;
		aver_dis*=10;
		aver_dis = round(aver_dis);
		aver_dis/=10;
		printf("%.1f %.1f\n",(double)max_dis,aver_dis);
	}
	else{
		printf("No Solution\n");
	}
	return 0;
}
