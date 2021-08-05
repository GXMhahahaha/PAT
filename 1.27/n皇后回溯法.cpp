//回溯法 n皇后问题
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn = 100;
int N;
int num;
int pos[maxn];
void DFS(int index){
	if(index == N){
		num++;
	}
	for(int i=0;i<N;i++){
		bool flag = true; 
		for(int j=0;j<index;j++){
			if(i==pos[j] || abs(i-pos[j]) == abs(index-j)){
				flag = false;
				break;
			}

		}
		if(flag == true){
			pos[index] = i;
			DFS(index+1);	
		}
	}
	
}

int main(){
	cin>>N;
	DFS(0);
	cout<<num;
	
	return 0;
}
