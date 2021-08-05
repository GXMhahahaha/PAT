//A1032 Sharing
#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 100010;
struct Node{
	char data;
	int address;
	int next;
	bool visited = 0;
}node[maxn];


int main(){
	int f1_add,f2_add,total;
	cin>>f1_add>>f2_add>>total;
	for(int i=0;i<total;i++){
		int add;
		char da;
		int ne;
		scanf("%d %c %d",&add,&da,&ne);
		
		node[add].address = add;
		node[add].data = da;
		node[add].next = ne;
		
		
	}
	
	//int len1=0,len2=0;
	int add = f1_add;
	
	while(add!=-1){
		node[add].visited = 1;
		add = node[add].next;
	}
	
	add = f2_add;
	while(add!=-1){
		if(node[add].visited == 1){
			printf("%05d\n",add);
			return 0;
		}
		add = node[add].next;
	}
	printf("-1\n");
	
	return 0;
} 
