//A1052 Linked List Sorting
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int addr;
	int data;
	int next;
	bool valid = 0;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.valid==0 || b.valid==0){
		return a.valid > b.valid;
	}
	else{
		return a.data < b.data;
	}
}

int main(){
	int N,first_add;
	cin>>N>>first_add;
	for(int i=0;i<N;i++){
		int ad,da,ne;
		scanf("%d %d %d",&ad,&da,&ne);
		node[ad].addr = ad;
		node[ad].data = da;
		node[ad].next = ne;
		
	}
	int point = first_add;
	
	int valid_num=0;
	while(point!=-1){
		node[point].valid=1;
		point = node[point].next;
		valid_num++;
	}
	sort(node,node+maxn,cmp);
	//point = node[0].addr;
	int i=0;
	while(i<valid_num){
		node[i].next = node[i+1].addr;
		i++;
	}
	node[i-1].next = -1;
	i=0;
	
	if(valid_num == 0){
		printf("0 -1\n");
		return 0;
	}
	
	printf("%d %05d\n",valid_num,node[0].addr);	
	
	while(node[i].next!=-1){
		printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i].next);
		i++;
	}
	printf("%05d %d %d\n",node[i].addr,node[i].data,node[i].next);
	return 0;
}
