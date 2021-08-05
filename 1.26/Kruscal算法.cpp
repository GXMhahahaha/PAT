//Kruscal Ëã·¨ 
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int vexnum,edgenum;

struct Edge{
	int u;
	int v;
	int wei;
}edge[maxn];

int Father[maxn];

int findFather(int u){
	if(Father[u] == u){
		return u;
	}
	else{
		int v = findFather(Father[u]);
		Father[u] = v;
		return v;
	}
}

bool cmp(Edge a,Edge b){
	return a.wei < b.wei;
}

int kruscal(){
	for(int i=0;i<vexnum;i++){
		Father[i] = i;
	}
	sort(edge,edge+edgenum,cmp);
	
	int num = 0;
	int totalcost = 0;
	while(num < vexnum-1){
		for(int i=0;i<edgenum;i++){
			int f1 = findFather(edge[i].u);
			int f2 = findFather(edge[i].v);
			if(f1!=f2){
				Father[f1] = f2;
				totalcost+=edge[i].wei;
				num++;
				
			}
		}
	}
	return totalcost;
}

int main(){
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].wei);
	}
	cout<<kruscal()<<endl;
	return 0;
} 
