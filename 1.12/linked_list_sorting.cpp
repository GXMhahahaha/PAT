//PAT A1052
//纯链表法导致超时，因为单纯用链表时间是O(n^2) 
#include <stdio.h>
#include <iostream>

struct NODE{
	int key;
	int next;
	bool visit;
}node[100010];

#define head1_addr 100008
#define head2_addr 100009

int main(){
	int N;int fir_addr;
	scanf("%d %d",&N,&fir_addr);
	
	node[head1_addr].next = fir_addr;
	node[head2_addr].next = -1;
	
	for(int i=0;i<N;i++){
		int add;
		scanf("%d ",&add); 
		scanf("%d %d",&node[add].key,&node[add].next);
	}
	int pre;
	int i;
	int max = -100010;
	
	int pre_pos, curr_pos;
	
	while(node[head1_addr].next != -1){
		pre = head1_addr;
		i = node[head1_addr].next;
		while(i != -1){
			if(node[i].key > max){
				pre_pos = pre;
				curr_pos = i;
				max = node[i].key;
			}
			pre = i;
			i = node[i].next;
		}
		
		node[pre_pos].next = node[curr_pos].next;
		node[curr_pos].next = node[head2_addr].next;
		node[head2_addr].next = curr_pos;
		max = -100010;	
	}
	

	
	int j = node[head2_addr].next;
	printf("%d %05d\n",N,j);
	
	while(node[j].next != -1){
		printf("%05d %d %05d\n",j,node[j].key,node[j].next);
		j = node[j].next;	
	}
	printf("%05d %d %d",j,node[j].key,node[j].next);

	
	
	return 0;
} 
