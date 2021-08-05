//A1086 Tree Traversals Again
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
const int maxn = 50;
int N;
int pre[maxn];
int in[maxn];
stack<int> s;

struct Node{
	int key;
	Node* left;
	Node* right;
};


Node* Build(int preL,int preR,int inL,int inR){
	if(preL>preR || inL>inR){
		return NULL;
	}
	Node* root = (Node*)malloc(sizeof(Node)*1);
	int Key = pre[preL];
	root->key = Key;
	int pos = -1;
	for(int i=inL;i<=inR;i++){
		if(in[i] == Key){
			pos = i;
			break;
		}
	}
	
	int numL = pos - inL;
	int numR = inR - pos;
	
	root->left = Build(preL+1,preL+numL,inL,pos-1);
	root->right = Build(preR-numR+1,preR,pos+1,inR);
	return root;
}

int cal = 0;
void PostOrder(Node* root){
	if(root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d",root->key);
	cal++;
	if(cal<N){
		printf(" ");
	}
}

int main(){
	cin>>N;
	int num=0;
	int i=0,j=0;
	
	while(1){
		char inst[5];		
		scanf("%s",inst);
		if(strcmp(inst,"Push")==0){
			int key;
			scanf("%d",&key);
			s.push(key);
			pre[i++] = key;
			num++; 
		}
		else{
			int key = s.top();
			in[j++] = key;
			s.pop();
		}
		if(num==N && s.empty()){
			break;
		}
	}
	
	Node* root = Build(0,i-1,0,j-1);
	PostOrder(root);
	printf("\n");
	return 0;
}
