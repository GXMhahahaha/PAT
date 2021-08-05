//A1090 Highest Price in Supply Chain
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 100010;

vector<int> node[maxn];
int N;
double basic,multi;

int num = 0;
int maxlayer = -1;
double ans = 0;
void DFS(int root,int index){
	if(node[root].size()==0){
		if(index > maxlayer){
			maxlayer = index;
			num = 0;
			num++;
			ans = basic*pow(1+multi/100,index); 
		}
		else if(index == maxlayer){
			num++;
		}
	}
	else{
		for(int i=0;i<node[root].size();i++){
			DFS(node[root][i],index+1);
		}
	}
	
}
 
int main(){
	cin>>N>>basic>>multi;
	int root;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		if(temp!=-1){
			node[temp].push_back(i);	
		}
		else{
			root = i;
		}
		
	}
	DFS(root,0);
	ans*=100;
	ans = round(ans);
	ans/=100;
	printf("%.2f %d\n",ans,num);
	return 0;
}
