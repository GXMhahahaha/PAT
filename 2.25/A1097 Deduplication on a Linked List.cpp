//A1097 Deduplication on a Linked List
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
#define endl '\n'
const int maxn = 100010;
struct Node{
	int addr;
	int key;
	int next;
	bool flag = 1;
	int order = INF;
}node[maxn];

bool visited[10010] = {0};
bool cmp(Node a,Node b){
	if(a.flag != b.flag){
		return a.flag < b.flag;
	}
	else{
		return a.order < b.order;
	}
}
int main(){
	int fir_add,N;
	cin>>fir_add>>N;
	for(int i=0;i<N;i++){
		int add,ke,ne;
		scanf("%d %d %d",&add,&ke,&ne);
		node[add].addr = add;
		node[add].key = ke;
		node[add].next = ne;
	}
	int pointer = fir_add;
	
	int valid_num = 0;
	int fir_num = 0,sec_num = 0;
	
	while(pointer!=-1){
		valid_num++;
		
		if(visited[abs(node[pointer].key)] == 0){
			node[pointer].flag = 0;
			fir_num++;
			visited[abs(node[pointer].key)] = 1;		
		}
		
		node[pointer].order = valid_num;
		pointer = node[pointer].next;
		
	}

	sec_num = valid_num - fir_num;
	sort(node,node+maxn,cmp);
	
	for(int i=0;i<valid_num;i++){
		node[i].next = node[i+1].addr;
	}
	node[fir_num-1].next = -1;
	node[valid_num-1].next = -1;
	
	int i=0;
	while(i<fir_num-1){
		printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i].next);
		i++;	
	}
	printf("%05d %d %d\n",node[i].addr,node[i].key,node[i].next);
	i++;
	if(sec_num!=0){
		while(i<valid_num-1){
			printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i].next);
			i++;	
		}
		printf("%05d %d %d\n",node[i].addr,node[i].key,node[i].next);			
	}

	return 0;
}
