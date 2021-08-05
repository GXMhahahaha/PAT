#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxsize = 100;
struct Node{
	int weight;
	vector<int> child; 
}node[maxsize];

int N,M,W;

int visit[maxsize];

bool cmp(int a,int b){
	return node[a].weight > node[b].weight;
}

void DFS(int index,int cur,int total_w){
	if(node[index].weight + total_w == W){
		if (node[index].child.size()!=0){
			return;
		}
		visit[cur] = index;
		
		for(int i=0;i<=cur;i++){
			printf("%d",node[visit[i]].weight);
			if(i<cur){
				printf(" ");
			}
			else{
				printf("\n");
			}			
		}


		return;
	}
	
	if(node[index].weight + total_w < W){
		visit[cur] = index;
		total_w += node[index].weight;
		for(vector<int> ::iterator i = node[index].child.begin();i!= node[index].child.end();i++){            //此处可以直接用数字下标； 
			DFS(*i,cur+1,total_w);
		}
	}
	
	if(node[index].weight + total_w > W){
		return;
	}
}

int main(){
	cin>>N>>M>>W;
	
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		node[i].weight = temp;
	}
	
	for(int i=0;i<M;i++){
		int index, childnum; 
		scanf("%d %d",&index,&childnum);
	 	for(int j=0;j<childnum;j++){
	 		int child_index;
	 		scanf("%d",&child_index);
	 		node[index].child.push_back(child_index);
		 }
		sort(node[index].child.begin(),node[index].child.end(),cmp);										//sort可以使用迭代器也可以用数组下标 
		//sort(node[index].child.begin(),node[index].child.begin()+childnum,cmp);                           //随机访问迭代器可以加减整数 
	}
	
	DFS(0,0,0);
	

	return 0;
}
