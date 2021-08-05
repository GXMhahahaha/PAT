//A1046 Shortest Distance 需要预先存储各个顶点到一号顶点的距离 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int dis[maxn];
int wei[maxn] = {0}; 

int N;
int total;

int Find(int a,int b){
	int sou = min(a,b);
	int des = max(a,b);
	int temp1 = wei[des] - wei[sou];
	int temp2 = total-temp1;
	return min(temp1,temp2);
}
int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>dis[i+1];
		total+=dis[i+1];
		wei[i+2] = wei[i+1] + dis[i+1];
	}
	int M;
	cin>>M;

	for(int i=0;i<M;i++){
		int source,dest;
			cin>>source>>dest;
			cout<<Find(source,dest)<<endl;
	}
	return 0;
} 
