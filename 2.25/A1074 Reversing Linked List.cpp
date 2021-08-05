//A1074 Reversing Linked List
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0X7fffffff
const int maxn = 100010;
struct Node{
	int address;
	int Data;
	int Next;
	int order;
}node[maxn];

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(){
	for(int i=0;i<maxn;i++){
		node[i].order = INF;
	}
	int first_address,num_of_data,K;
	cin>>first_address>>num_of_data>>K;
	
	for(int i=0;i<num_of_data;i++){
		int add,da,ne;
		scanf("%d %d %d",&add,&da,&ne);
		node[add].address = add;
		node[add].Data = da;
		node[add].Next = ne;
	}
	int point = first_address;
	int ord = 1;
	while(point!=-1){
		node[point].order = ord++;
		point = node[point].Next;
	}
	sort(node,node+maxn,cmp);

	int head = 0,tail = 0;
	bool if_first = 1;
	while(tail<ord-1){
		tail = head+K-1;
		if(tail>=ord-1){
			break;
		}

		int index = tail;
		int tail_next = node[tail].Next;
		while(index>head){
			node[index].Next = node[index-1].address;
			index--;
		}
		node[index].Next = tail_next;
		reverse(node+head,node+tail+1);
		if(head>0){
			node[head-1].Next = node[head].address;
		}
		tail++;
		head = tail;
	}
	
	for(int i=0;i<ord-2;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].Data,node[i].Next);
	}
	printf("%05d %d %d\n",node[ord-2].address,node[ord-2].Data,node[ord-2].Next);
	return 0;
}
