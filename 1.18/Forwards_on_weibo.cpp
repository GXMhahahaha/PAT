#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 10010;
int N,L;

struct Node{
	int id;
	int layer;
	Node(){}
	Node(int _id,int _layer){
		id = _id;
		layer = _layer;
	}
};

vector<Node> Adj[maxn];
bool in_que[maxn] = {0};
queue<Node> Q;

int BFS(int s){
	int num = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	in_que[start.id] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i=0;i<Adj[u].size();i++){
			Node next = Adj[u][i];
			next.layer = topNode.layer+1;
			if(in_que[next.id] == false && next.layer<=L){
				q.push(next);
				in_que[next.id] = true;
				num++;
			}
		}
	}

	for(int i=1;i<=N;i++){
		in_que[i] = 0;
	}
	return num;
	
}

int main(){
	cin>>N>>L;
	for(int i=0;i<N;i++){
		int k,temp;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&temp);
			Adj[temp].push_back(Node(i+1,0));
			
		} 
	}
	

	int out_num;
	scanf("%d",&out_num);
	for(int i=0;i<out_num;i++){
	
		int index;
		scanf("%d",&index);
		int temp = BFS(index);
		printf("%d\n",temp);

	}
		 
	return 0;
} 
