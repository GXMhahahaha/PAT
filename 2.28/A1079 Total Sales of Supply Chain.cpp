//A1079 Total Sales of Supply Chain
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl '\n'
using namespace std;
const int maxn = 100010;
struct Node{
	int ChildNum;
	vector<int> child;
	int layer;
	int total;
}node[maxn];

int N;
double s,p;

double Layer_Order(){
	queue<int> q;
	q.push(0);
	node[0].layer = 0;
	double ans = 0;
	
	while(!q.empty()){
		int pp = q.front();
		//cout<<pp<<endl;
		q.pop();
		if(node[pp].ChildNum == 0){
			ans+=node[pp].total*s*pow((1+(p/100)),node[pp].layer);
		}
		else{
			for(int i=0;i<node[pp].ChildNum;i++){
				int num = node[pp].child[i];
				node[num].layer = node[pp].layer+1; 
				q.push(num);
			}
		}
		
	}
	return ans;
}

int main(){
	cin>>N>>s>>p;
	for(int i=0;i<N;i++){
		int Chi_num;
		scanf("%d ",&Chi_num);
		node[i].ChildNum = Chi_num;
		if(Chi_num > 0){
			for(int j=0;j<Chi_num;j++){
				int temp;
				scanf("%d",&temp);
				node[i].child.push_back(temp);
			}
		}
		else{
			int temp;
			scanf("%d",&temp);
			node[i].total = temp;
			
		}
	}
	double ans = Layer_Order();
	ans*=10;
	ans = round(ans);
	ans/=10;
	printf("%.1f\n",ans);
	
	return 0;
}
