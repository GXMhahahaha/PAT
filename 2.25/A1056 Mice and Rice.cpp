//A1056 Mice and Rice
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1010;
struct Mouse{
	int wei;
	int rank;
}mouse[maxn];

queue<int> q;
int main(){
	int NP,NG;
	cin>>NP>>NG;
	int temp = NP;						//用来记录当前排序总人数 
	for(int i=0;i<NP;i++){
		scanf("%d",&mouse[i].wei);
	}
	for(int i=0;i<NP;i++){
		int order;
		scanf("%d",&order);
		q.push(order);
	}
	
	while(q.size()!=1){
		int group;
		if(temp%NG==0){
			group = temp/NG;
		}
		else{
			group = temp/NG+1;
		}
		for(int i=0;i<group;i++){
			int k = q.front();			//用来记录哪只老鼠最重 
			for(int j=0;j<NG;j++){
				if(i*NG+j>=temp){
					break;
				}
				int front = q.front();
				if(mouse[front].wei > mouse[k].wei){
					k = front;
				}
				mouse[front].rank = group+1;
				q.pop();
				
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].rank = 1;
	
	for(int i=0;i<NP;i++){
		printf("%d",mouse[i].rank);
		if(i<NP-1){
			printf(" ");
		}
	}	
	printf("\n");	
	return 0;
}
