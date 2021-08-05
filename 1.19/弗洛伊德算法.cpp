//弗洛伊德算法   全源最短路径 
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff
const int maxn = 200;
int vexnum,edgenum;
int G[maxn][maxn];

void Floyd(){
	for(int k=0;k<vexnum;k++){
		for(int i=0;i<vexnum;i++){
			for(int j=0;j<vexnum;j++){
				if(G[i][k]!=INF && G[k][j]!=INF && G[i][k]+G[k][j]<G[i][j])
					G[i][j] = G[i][k]+G[k][j];
			}
		}
	} 
	
}

int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<maxn;i++){
		G[i][i] = 0;
	}
	
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
	 	int sou,des,dis;
		cin>>sou>>des>>dis;
		G[sou][des] = dis;
	}
	
	Floyd();
	for(int i=0;i<vexnum;i++){
		for(int j=0;j<vexnum;j++){
			if(G[i][j] == INF){
				cout<<"*"<<" ";
			}
			else{
				cout<<G[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	
	
	return 0;
}

//测试数据 
//6 8
//0 1 1
//0 3 4
//0 4 4
//1 3 2
//2 5 1
//3 2 2
//3 4 3
//4 5 3
