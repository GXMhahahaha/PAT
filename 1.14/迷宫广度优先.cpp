//�Թ�
//��������㷨
#include <stdio.h>
#include <iostream>
#include <queue>
 
using namespace std;

const int maxm = 100;
const int maxn = 100;
char a[maxm][maxn];
int M,N;
int st_x,st_y,end_x,end_y;

int minstep = 1e5;
int step = 0;
int off_x[4] = {1,-1,0,0};
int off_y[4] = {0,0,1,-1};
bool in_que[maxm][maxn]={0};

struct COOR{
	int x;
	int y;
	int step;
	COOR(){}
	COOR(int _x,int _y,int _step){
		x = _x;
		y = _y;
		step = _step;
	}
};

queue<COOR> q;

bool is_qualified(int i,int j){
	if(i < 0 || i >= M && j <0 && j >= N )
		return false;
	else if(in_que[i][j] == 1)
		return false;
	else if(a[i][j] == '*')
		return false;
	else 
		return true;
}




int BFS(int i,int j){
	COOR point = COOR(i,j,0);
	q.push(point);
	in_que[i][j] = 1;
	while(!q.empty()){					//��������㷨�������Ԫ����û�����
		COOR temp;						//������һ��Ԫ�غ���Ҫ�ָ�ԭʼ״̬
		temp = q.front();					//��Ϊ��һ���Ԫ���Ѿ������꣬�����ظ����� 
		if(temp.x == end_x && temp.y == end_y){
			return temp.step;						//��Ϊ��һ��һ������ģ�����һ�η��ʵ�Ŀ�Ľڵ�ʱ����Ȼ�ǲ�����̣� 
		}
		else{
			for(int k=0;k<4;k++){
				COOR _temp; 
				_temp.x = temp.x+off_x[k];
				_temp.y = temp.y+off_y[k];
		
				if(is_qualified(_temp.x,_temp.y)){
					_temp.step = temp.step+1;
					q.push(_temp);
					in_que[_temp.x][_temp.y] = 1;
					
								
				}
				
		
			}
			q.pop();	
		}
		
	}
}
	
	
int main(){
	cin>>M>>N;
	

	for(int i=0;i<M;i++){
		getchar();					//ȥ�����з� 
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
	
	cout<<BFS(st_x,st_y)<<endl;
	
	
	return 0;
} 
