//迷宫
//深度优先算法
#include <stdio.h>
#include <iostream>

using namespace std;

const int maxm = 100;
const int maxn = 100;
char a[maxm][maxn];
int M,N;
int minstep = 1e5;
int off_x[4] = {1,-1,0,0};
int off_y[4] = {0,0,1,-1};
bool visited[maxm][maxn]={0};

void DFS(int i,int j,int& step,int& minstep){
	if(i<0 || i>=M || j<0 || j>=N){
		return ;
	}
	
	else if(a[i][j] == 'T'){
		
		if(step < minstep){
			minstep = step;
		}
		return;		
	}
	 
	else if(a[i][j] == '.' || a[i][j] == 'S'){
		if(visited[i][j] == 1)
			return;
		else {
			visited[i][j] = 1;
			step++;
			
			for(int k=0;k<4;k++){
				int rx,ry; 
				rx = i+off_x[k];
				ry = j+off_y[k];
				DFS(rx,ry,step,minstep);
			
			}
			visited[i][j] = 0;
			step--; 
		}

	}
	else if(a[i][j] == '*')
		return;
}
	

int main(){
	cin>>M>>N;
	int st_x,st_y,end_x,end_y;

	for(int i=0;i<M;i++){
		getchar();					//去掉换行符 
		for(int j=0;j<N;j++){
			scanf("%c",&a[i][j]);
			if(a[i][j] == 'S'){
				st_x = i;
				st_y = j;
			}
			else if(a[i][j] == 'T'){
				end_x = i;
				end_y = j;
			}
		}
	}
	
	int step = 0;
	DFS(st_x,st_y,step,minstep);
	cout<<minstep<<endl;
	cout<<step<<endl;
	
	
	return 0;
} 
