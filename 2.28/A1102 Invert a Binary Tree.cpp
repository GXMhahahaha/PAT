//A1102 Invert a Binary Tree
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 15;
struct Node{
	int left;
	int right;
}node[maxn];
int N;
bool if_root[maxn];

int changeTonum(char a){
	if(a == '-'){
		return maxn-1;
	}
	else{
		int ans = a-'0';
		if_root[ans] = 0;
		return ans;
	}
}

int Search_Root(){
	for(int i=0;i<N;i++){
		if(if_root[i] == 1){
			return i;
		}
	}
}

void Reverse(int root){
	if(root == maxn-1){
		return;
	}
	
	int left_child = node[root].left;
	int right_child = node[root].right;
	
	Reverse(left_child);
	Reverse(right_child);
	swap(node[root].left,node[root].right);

}

void LayerOrder(int root){
	queue<int> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		num++;
		printf("%d",p);
		if(node[p].left!=maxn-1){
			q.push(node[p].left);
		}
		if(node[p].right!=maxn-1){
			q.push(node[p].right);
		}
		if(num<N){
			printf(" ");
		}
		
	} 

}

int counter = 0;
void InOrder(int root){
	if(root == maxn-1){
		return;
	}
	InOrder(node[root].left);
	
	printf("%d",root);
	counter++;
	if(counter<N){
		printf(" ");
	}
	
	InOrder(node[root].right);	
}
int main(){
	fill(if_root,if_root+maxn,1);
	cin>>N;
	getchar();
	for(int i=0;i<N;i++){
		char le,ri;
		scanf("%c %c",&le,&ri);
		node[i].left = changeTonum(le);
		node[i].right = changeTonum(ri);
		getchar();
	}
	int root = Search_Root();
	Reverse(root);
	LayerOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	return 0;
} 
