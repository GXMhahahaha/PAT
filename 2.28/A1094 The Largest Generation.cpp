//A1094 The Largest Generation
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int layer_num[maxn] = {0};
int N,M;

void DFS(int root,int index){
	layer_num[index]++;
	if(child[root].size()==0){
		return;
	}
	for(int i=0;i<child[root].size();i++){
		DFS(child[root][i],index+1);
	}
	
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int pos,childnum;
		scanf("%d %d",&pos,&childnum);
		for(int j=0;j<childnum;j++){
			int ch;
			scanf("%d",&ch);
			child[pos].push_back(ch);
		}
	}		
	DFS(1,0);
	int max = -1;
	int layer = 0;
	for(int i=0;i<maxn;i++){
		if(layer_num[i] > max){
			max = layer_num[i];
			layer = i+1;
		}
	}
	cout<<max<<" "<<layer<<endl; 
	return 0;
} 
