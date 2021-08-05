//插入节点使用循环插入 
//vector可以直接两两比较大小 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxsize = 1010;
int N;
int a[maxsize];


struct Node{
	int key;
	Node* left;
	Node* right;
};

void insert_BS(Node*& root,int num){
	if(root == NULL){
		root = new(Node);
		root->key = num;
		root->left = NULL;
		root->right = NULL;
	}
	else if(num < root->key){
		insert_BS(root->left,num);
	}
	else if(num >= root->key){
		insert_BS(root->right,num);
	}
														 
}




void insert_nBS(Node*& root,int num){
	if(root == NULL){
		root = new(Node);
		root->key = num;
		root->left = NULL;
		root->right = NULL;
	}
	else if(num >= root->key){
		insert_nBS(root->left,num);
	}
	else if(num < root->key){
		insert_nBS(root->right,num);
	}
														 
}


void Pre_order(Node* root,vector<int>& vi){
	if(root == NULL) return;
	vi.push_back(root->key);
	Pre_order(root->left,vi);
	Pre_order(root->right,vi);
}

void Post_order(Node* root,vector<int>& vi){
	if(root == NULL) return;
	Post_order(root->left,vi);
	Post_order(root->right,vi);
	vi.push_back(root->key);
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);		
	}
	
	vector<int> original;
	for(int i=0;i<N;i++){
		original.push_back(a[i]);
	}
	
	Node* root1 = NULL;
	Node* root2 = NULL;

	for(int i=0;i<N;i++){
		insert_BS(root1,a[i]);
	}
	
	for(int i=0;i<N;i++){
		insert_nBS(root2,a[i]);		
	}	

	
	vector<int> pre1,pre2,post;
	
	Pre_order(root1,pre1);
	Pre_order(root2,pre2);
	
		
	if(original == pre1 || original == pre2){
		cout<<"YES"<<endl;
		if(original == pre1){
			Post_order(root1,post);
			for(int i=0;i<post.size();i++){
				printf("%d",post[i]);
				if(i<post.size()-1){
					printf(" ");
				}
			}
		}
		else{
			Post_order(root2,post);
			for(int i=0;i<post.size();i++){
				printf("%d",post[i]);
				if(i<post.size()-1){
					printf(" ");
				}
			}
		}
	}
	else{
		printf("NO"); 
	}
	
	return 0;
}
