//n皇后问题简单递归
#include <stdio.h>
#include <math.h>

const int maxsize = 100;
bool visited[maxsize]={0};
int rout[maxsize];
int N;
int num = 0;

void gen(int layer){
	if(layer == N+1){
		num++; 
		return;
	}
	for(int x=1;x<=N;x++){
		bool flag = 0;
		if(visited[x]==0){
			for(int i=1;i<layer;i++){
				if(abs(x-rout[i])==abs(layer-i)){
					flag = 1;		//flag为1表示有冲突 
					break;
				}
					 
				
			}
			
			if(flag == 1) 
				continue;
			
			else{
				rout[layer] = x;
				visited[x] = 1;
				gen(layer+1);
				visited[x] = 0;
			}
			
		}
	}
	
	
}


int main (){
	scanf("%d",&N);
	gen(1);
	printf("%d",num);
	return 0;
}
