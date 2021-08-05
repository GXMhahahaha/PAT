//A1034 Head of a Gang
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2010;
struct Vex{
	string name;
	int indegree = 0;
	int outdegree = 0;
}vex[maxn];

int N,K;
int counter = 0;					//记录有多少节点 
vector<int> Adj[maxn];
map<string,int> mp;
bool visited[maxn] = {0};

struct ANS{
	string name;
	int member_num;
};

vector<ANS> ans;

bool DFS_traverse(int u,int& totalwei,int& maxwei,int& head,int& nodenum){				//使用引用产生了累加效应 
	bool flag = false;
	visited[u] = 1;
	if(vex[u].indegree+vex[u].outdegree>maxwei){
		maxwei = vex[u].indegree+vex[u].outdegree;
		head = u;
	}
	totalwei+=vex[u].outdegree;
	nodenum++;
	for(int i=0;i<Adj[u].size();i++){
		int vex_num = Adj[u][i];
		if(visited[vex_num] == 0){
			DFS_traverse(vex_num,totalwei,maxwei,head,nodenum);
		}
	}
	if(totalwei > K && nodenum > 2){
		flag = true;
	}
	return flag;
	
}
bool cmp(ANS a,ANS b){
	return a.name < b.name;
}

int main(){
	cin>>N>>K;
	
	for(int i=0;i<N;i++){
		string str1,str2;
		cin>>str1>>str2;
		if(mp.count(str1) == 0){
			mp[str1] = counter++;
		}
		if(mp.count(str2) == 0){
			mp[str2] = counter++;
		}
		int wei;
		scanf("%d",&wei);
		int index1 = mp[str1];
		int index2 = mp[str2];

		Adj[index1].push_back(index2);
		
		vex[index1].name = str1;
		vex[index1].outdegree+=wei;
		vex[index2].name = str2;
		vex[index2].indegree+=wei;
	}
	
	
	for(int i=0;i<counter;i++){
		if(visited[i] == 0){
			int total_wei=0,maxwei=0,head=i,nodenum=0;
			if(DFS_traverse(i,total_wei,maxwei,head,nodenum)){
				ANS temp;
				temp.name = vex[head].name;
				temp.member_num = nodenum;
				ans.push_back(temp);
				
			}
		}
	}

	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<endl; 
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].name<<" "<<ans[i].member_num<<endl;
	}		

	return 0;
}
