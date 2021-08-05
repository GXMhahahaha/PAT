//A1066 Root of AVL Tree
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 30;
struct Node{
	int key;
	Node* left;
	Node* right;
};

int getHeight(Node* root){
	if(root == NULL){
		return 0;
	}
	return 1+max(getHeight(root->left),getHeight(root->right));
}

int getBalanceFactor(Node* root){
	if(root == NULL){
		return 0;
	}
	return getHeight(root->left) - getHeight(root->right);
} 

void L(Node* &root){
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root = temp;
}

void R(Node* &root){
	Node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root = temp;
	
}


void Insert(Node* &root,int K){
	if(root == NULL){
		root = new(Node);
		root->key = K;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(K<root->key){
		Insert(root->left,K);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->left) == 1){
				R(root);
			}
			else if(getBalanceFactor(root->left) == -1){
				L(root->left);
				R(root);
			}
		}	
	}
	else{
		Insert(root->right,K);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->right) == 1){
				R(root->right);
				L(root);
			}
			else if(getBalanceFactor(root->right) == -1){
				L(root);
			
			}
		}	
	}
	
}

int main(){
	int N;
	cin>>N;
	
	Node* root = NULL;
	for(int i=0;i<N;i++){
		int key;
		scanf("%d",&key);
		Insert(root,key);
				
	}
  	printf("%d\n",root->key);
	
	return 0;
}
