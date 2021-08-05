//A1106 Lowest Price in Supply Chain
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl '\n'
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];

int N;
double s,p;

int num=0,layer=maxn;

void DFS(int root,int index){
	if(child[root].size() == 0){
		if(index < layer){
			num=0;
			num++;
			layer = index;
		}
		else if(index == layer){
				num++;
		}
		return;
	}
	
	else{
		for(int i=0;i<child[root].size();i++){
			DFS(child[root][i],index+1);
		}
	}
	
}

int main(){
	cin>>N>>s>>p;
	for(int i=0;i<N;i++){
		int Chi_num;
		scanf("%d",&Chi_num);
		if(Chi_num > 0){
			for(int j=0;j<Chi_num;j++){
				int temp;
				scanf("%d",&temp);
				child[i].push_back(temp);
			}
		}
	
	}
	
	DFS(0,0);
	double ans = s*pow(1+p/100,layer);
	printf("%.4f %d\n",ans,num);	

	return 0;
}
