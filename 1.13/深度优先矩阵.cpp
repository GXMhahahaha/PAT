//深度优先算法
//矩阵块
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int maxm = 100;
const int maxn = 100; 
int a[maxm][maxn];//二维数组的fill函数一会测试一下 
bool visited[maxm][maxn] = {0};

struct coor{
	int x;
	int y;
};
int total = 0;

int m;int n;

int x_off[4] = {0,0,1,-1};
int y_off[4] = {1,-1,0,0};

int DFS(int i,int j){
	
		if(a[i][j] == 1 && visited[i][j] == 0){
			visited[i][j] = 1;
			for(int k=0;k<4;k++){
				int t_x = i+x_off[k];
				int t_y = j+y_off[k];
		
					if(t_x >= 0 && t_x < m && t_y >= 0 && t_y < n){
						if(!visited[t_x][t_y] && a[t_x][t_y] == 1){
							DFS(t_x,t_y);
							
					}		
				}
					
						
			}
		return 1;
		}
		else
			return 0;
				
}	


int main(){
	
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			total+=DFS(i,j);	
		}
	}
	

	cout<<total<<endl;
	
	
	return 0;
} 
