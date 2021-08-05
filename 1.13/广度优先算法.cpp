//广度优先算法
//矩阵块
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int maxm = 100;
const int maxn = 100; 
int a[maxm][maxn];//二维数组的fill函数一会测试一下 
bool in_q[maxm][maxn] = {0};

struct coor{
	int x;
	int y;
};

queue<coor> Q;

int x_off[4] = {0,0,1,-1};
int y_off[4] = {1,-1,0,0};

int main(){
	int m;int n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int total = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] == 0)
				continue;
			else {
				if(in_q[i][j] == 0){
					coor point;
					point.x = i;  point.y = j;
					Q.push(point);
					in_q[i][j] = 1;
					while(!Q.empty()){
						int _x = Q.front().x;
						int _y = Q.front().y;
						Q.pop();
						for(int k=0;k<4;k++){
							int t_x = _x+x_off[k];
							int t_y = _y+y_off[k];
							if(t_x >= 0 && t_x < m && t_y >= 0 && t_y < n){
								if(!in_q[t_x][t_y] && a[t_x][t_y] == 1){
									coor _point;
									_point.x = t_x;  _point.y = t_y;
									Q.push(_point);
									in_q[t_x][t_y] = 1;
								}		
							}
											
						}
					}
				total++;
				}					
			}

		}
	}
	
	cout<<total<<endl;
	
	
	return 0;
} 
