//1008 Elevator
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int cur = 0;
	int cost = 0;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		int sub = temp - cur;
		if(sub>0){
			cost+=sub*6;
		}
		else if(sub<0){
			cost+=(-sub)*4;
		}
		cur = temp;
	}
	cost+=N*5;
	cout<<cost<<endl;
	
	
	return 0;
} 
