//A1076 Forwards on Weibo
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int N,L;
vector<int> Adj[maxn];
int layer[maxn];
bool in_queue[maxn] = {0};

int BFS(int u){
	int total = 0;
	queue<int> q;
	q.push(u);
	in_queue[u] = 1;
	layer[u] = 0;
	
	while(!q.empty()){
		int front = q.front();
		if(layer[front] > L){
			break;
		}
		q.pop();
		total++;

		for(int i=0;i<Adj[front].size();i++){
			int vex_num = Adj[front][i];
			if(!in_queue[vex_num]){
				q.push(vex_num);
				layer[vex_num] = layer[front]+1;
				in_queue[vex_num] = 1;
			}
			
			
		}
	}
	return total;
}

int main(){
	cin>>N>>L;
	
	for(int i=0;i<N;i++){
		int num;
		scanf("%d ",&num);
		for(int j=0;j<num;j++){
			int temp;
			scanf("%d",&temp);
			Adj[temp].push_back(i+1);
		}	
	}
	int quire_num;
	scanf("%d",&quire_num);
	for(int i=0;i<quire_num;i++){
		int quire;
		scanf("%d",&quire);
		fill(in_queue,in_queue+maxn,0);
		cout<<BFS(quire)-1<<endl;
	}
	
	return 0;
}
