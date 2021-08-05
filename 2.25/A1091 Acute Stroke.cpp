//A1091 Acute Stroke
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int M,N,L,T;
int pixel[60][1286][128];
bool inq[60][1286][128] = {{{0}}};

struct Cor{
	int x;
	int y;
	int z;
};
int change[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

bool is_Valid(int x,int y,int z){
	if(x<0 || x>=L || y<0 || y>=M || z<0 || z>=N){
		return false;
	}
	else if(inq[x][y][z] == 1 || pixel[x][y][z] == 0){
		return false;
	}
    else{
        return true;
    }
}

int BFS(int i,int j,int k){
	int valid_num = 0;
	int total = 0;
	queue<Cor> q;
	Cor cor;
	cor.x = i;
	cor.y = j;
	cor.z = k;
	q.push(cor);
	inq[i][j][k] = 1;
	while(!q.empty()){
		int oldX = q.front().x;
		int oldY = q.front().y;
		int oldZ = q.front().z;
		q.pop();
		valid_num++;
		for(int f=0;f<6;f++){
			int newX,newY,newZ;
			
			newX = oldX+change[f][0];
			newY = oldY+change[f][1];
			newZ = oldZ+change[f][2];
			
			if(is_Valid(newX,newY,newZ)){
				Cor node;
				node.x = newX;
				node.y = newY;
				node.z = newZ;
				q.push(node);
				inq[newX][newY][newZ] = 1;

			}
	
		}
	}
	if(valid_num >= T){
		total = valid_num;
	}
	return total; 
}
int main(){
	cin>>M>>N>>L>>T;
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				scanf("%d",&pixel[i][j][k]);
			}
		}
	}
	
	int ans = 0;
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(pixel[i][j][k]==1 && !inq[i][j][k]){
					ans+=BFS(i,j,k);
				}
			}
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}
