//插入节点使用循环插入 
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

void change(Node*& root){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL){
		return;
	}
	else{
		Node* temp = root->left;
		root->left = root->right;
		root->right = temp; 
		change(root->left);
		change(root->right);		
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
	
	Node* root = NULL;

	for(int i=0;i<N;i++){
		insert_BS(root,a[i]);
	}
	
	vector<int> pre1,pre2,post1,post2;
	Pre_order(root,pre1);
	Post_order(root,post1);
	
	change(root);
	Pre_order(root,pre2);
	Post_order(root,post2);
	
		
	if(original == pre1 || original == pre2){
		cout<<"YES"<<endl;
		if(original == pre1){
			for(int i=0;i<post1.size();i++){
				printf("%d",post1[i]);
				if(i<post1.size()-1){
					printf(" ");
				}
			}
		}
		else{
			for(int i=0;i<post2.size();i++){
				printf("%d",post2[i]);
				if(i<post2.size()-1){
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
