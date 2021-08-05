//深度优先算法
//背包问题

#include <iostream>
using namespace std;

const int maxsize = 1e5;
int maxvalue = -1;
int num,M;

struct Pack{
	int mass;
	int value;
	bool flag = 0;
}pack[maxsize];

bool if_choose[maxsize] = {0};

void DFS(int index,int sum_mass,int sum_value){
	if(index == num){
		if(sum_value > maxvalue){
			maxvalue = sum_value;
			for(int i=0;i<num;i++){
				if_choose[i] = pack[i].flag;
			}
		}
	}
	
	else if(pack[index].mass+sum_mass > M){
		pack[index].flag = 0;
		DFS(index+1,sum_mass,sum_value);
	}
	else{
		pack[index].flag = 1;					//选这件物品
		DFS(index+1,sum_mass+pack[index].mass,sum_value+pack[index].value);  
		pack[index].flag = 0;					//不选这件物品
		DFS(index+1,sum_mass,sum_value);
	}
	
}




int main(){
	
	cin>>num>>M;
	for(int i=0;i<num;i++){
		cin>>pack[i].mass;
	}
	for(int i=0;i<num;i++){
		cin>>pack[i].value;
	}
	DFS(0,0,0);
	
	for(int i=0;i<num;i++){
		cout<<if_choose[i];
	}
	cout<<endl<<maxvalue;
	
	
	
	return 0;
} 
