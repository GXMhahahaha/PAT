//A1099 Build A Binary Search Tree
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
int N;

struct Node{
	int key;
	int left;
	int right;
}node[maxn];
int wei[maxn];

int index = 0;
void Inorder(int root){
	if(root == -1){
		return;
	}
	Inorder(node[root].left);
	node[root].key = wei[index++];
	Inorder(node[root].right);
	
}

void Levelorder(int root){
	queue<int> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		num++;
		printf("%d",node[front].key);
		if(num<N){
			printf(" ");
		}
		if(node[front].left!=-1){
			q.push(node[front].left);
		}
		if(node[front].right!=-1){
			q.push(node[front].right);
		}		
		
		
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d %d",&node[i].left,&node[i].right);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&wei[i]);
	}
	sort(wei,wei+N);
	Inorder(0);
	Levelorder(0);
	cout<<endl;
	return 0;
}
