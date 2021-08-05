//PAT A1052
//纯链表法导致超时，因为单纯用链表时间是O(n^2) 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std; 

struct NODE{
	int key;
	int next;
	int pos;
	bool visit = 0;
}node[100010];

bool cmp(NODE node1,NODE node2){
	if(node1.visit != node2.visit){
		return node1.visit > node2.visit;
	}
	else return node1.key < node2.key;
	
}
int main(){
	int N;int fir_addr;
	scanf("%d %d",&N,&fir_addr);
	
	int num = 0;
	
		
	for(int i=0;i<N;i++){
		int add;
		scanf("%d ",&add); 
		scanf("%d %d",&node[add].key,&node[add].next);
	//	node[add].visit = 1;
		node[add].pos = add;
	//	num++;
	}
	
	//必须遍历一次，因为输入可能有无效节点，即节点并不在链表之中
	int pos = fir_addr;
	while(pos != -1){
		node[pos].visit = 1;
		num++;
		pos=node[pos].next;
	}
	
	//有可能输入了节点 但是这些节点不在目的链表上 
	if(num == 0){
		printf("0 -1");
		return 0; 
		
	}
	 
	sort(node,node+100010,cmp);
	
	printf("%d %05d\n",N,node[0].pos);
	
	int i;
	for(i=0;i<num-1;i++){
		printf("%05d %d %05d\n",node[i].pos,node[i].key,node[i+1].pos);
	}
		printf("%05d %d -1\n",node[i].pos,node[i].key);
	

	return 0;
} 
