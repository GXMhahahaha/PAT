#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxsize = 30;
 
int N;
int post[maxsize],in[maxsize];


struct Node{
	int data;
	Node *left = NULL;
	Node *right = NULL;
};

queue<Node*> Q;

Node* Creat(int p_left,int p_right,int i_left,int i_right){
	if(p_left > p_right){
		return NULL;
	}
	else{																		//�����ò���else��ʵ����ν������return�ˣ�Ҳ������ɶ���ĸ��Ӷ� 
		Node* p = new(Node);
		p->data = post[p_right];
		int pos;
		for(pos=0;pos<N;pos++){
			if(in[pos] == post[p_right])
				break;
		}
		int llen = pos-i_left;
		p->left = Creat(p_left,p_left+llen-1,i_left,i_left+llen-1);				//ʼ��ʹ��left��right��Ҫ���� ��0 ��  
		p->right = Creat(p_left+llen,p_right-1,pos+1,i_right);
		return p;		
	}
}

void levelorder(Node* root){
	if(root == NULL){
		return;
	}
	else{
		Q.push(root);
		while(!Q.empty()){
			Node* node = Q.front();
			if(Q.size() == 1 && node->left == NULL && node->right == NULL){
				printf("%d",node->data);
			}
			else{
				printf("%d ",node->data);
			}
			if(node->left != NULL){
				Q.push(node->left);
			}
			
			if(node->right != NULL){
				Q.push((node->right));
			}
			Q.pop();
		}
	}	
}

int main(){
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);	
	}
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);	
	}	
	
	Node* root = Creat(0,N-1,0,N-1);
	levelorder(root);
	
	return 0;
} 
