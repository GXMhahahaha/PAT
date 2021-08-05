//A1043 Is It a Binary Search Tree
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ori,pre_order,mirror;
int N;
struct Node{
	int key;
	Node* left;
	Node* right;
};

void Insert(Node* &root,int temp){
	if(root == NULL){
		root = new(Node);
		root->key = temp;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(temp < root->key){
		Insert(root->left,temp);
	}
	else if(temp >= root->key){
		Insert(root->right,temp);
	}
	
}

void PreOrder(Node* root){
	if(root == NULL){
		return;
	}
	pre_order.push_back(root->key);	
	PreOrder(root->left);
	PreOrder(root->right);
} 

void Reverse(Node* root){
	if(root == NULL){
		return;
	}
	Reverse(root->left);
	Reverse(root->right);
	Node* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int count = 0;
void PostOrder(Node* root){
	if(root == NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d",root->key);
	count++;
	if(count<N){
		printf(" ");
	}
	
}
int main(){
	
	cin>>N;
	int first_key;
	scanf("%d",&first_key);
	Node* root = new(Node);
	root->key = first_key;
	root->left = NULL;
	root->right = NULL;
	ori.push_back(first_key);
	
	for(int i=1;i<N;i++){
		int temp;
		scanf("%d",&temp);
		ori.push_back(temp);
		Insert(root,temp);
	}

	PreOrder(root);
	if(ori == pre_order){
		printf("YES\n");
		PostOrder(root);
		cout<<endl;
		return 0;
	}
	pre_order.clear();
	Reverse(root);
	PreOrder(root);
	
	if(ori == pre_order){
		printf("YES\n");
		PostOrder(root);
		cout<<endl;
	}
	else{
		printf("NO\n");
	}

	return 0;
} 
