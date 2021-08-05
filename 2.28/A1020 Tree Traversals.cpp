//A1020 Tree Traversals
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 40;

int post_order[maxn];
int in_order[maxn];
int N;
struct Node{
	int key;
	Node* left;
	Node* right;
};

int Search(int Key){
	for(int i=0;i<N;i++){
		if(in_order[i] == Key){
			return i;
		}
	}
} 

Node* Build_Tree(int post_left,int post_right,int in_left,int in_right){
	if(post_left>post_right || in_left>in_right){
		return NULL;
	}
	int Key = post_order[post_right];
	int pos = Search(Key);
	
	int left_len = pos - in_left;
	int right_len = in_right - pos;
	
	Node* root = (Node*)malloc(sizeof(Node)*1);
	root->key = Key;
	root->left = Build_Tree(post_left,post_left+left_len-1,in_left,pos-1);
	root->right = Build_Tree(post_right-right_len,post_right-1,pos+1,in_right);
	return root;
	
}

void layer_order(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node * p = q.front();
		printf("%d",p->key);
		q.pop();
		if(p->left!=NULL){
			q.push(p->left);
		}
		if(p->right!=NULL){
			q.push(p->right);
		}
		if(q.size()>=1){
			printf(" ");
		}
		
	}
}

int main(){
	
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&post_order[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&in_order[i]);
	}
	Node*root = Build_Tree(0,N-1,0,N-1);
	layer_order(root);
    printf("\n");
	return 0;
} 
