#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>


#define endl "\n"
using namespace std;
int N,K;
const int maxsize = 2010;
int totalnum = 0;

struct Node{
	
	int id;
	int weight;
	Node(int _id,int _weight){
		id = _id;
		weight = _weight;
	}

};


struct Node_new{
	string name;
	int id;
	int in_weight = 0;
	int out_weight = 0;
	int gang_num;

	bool is_boss = 0;
	
	Node_new(){}
//	Node_new(string _name,int _id,int _gang_num){
//		name = _name;
//		id = _id;
//		gang_num = _gang_num;
//	}															初始化导致的之前数据被覆盖 
	
}node[maxsize]; 

struct Out{
	string name;
	int mem_num;
	Out(string _name,int _num){
		name = _name;
		mem_num = _num;
	}
};

vector<Node> Adj[maxsize];    							//邻接表 
map<string,int> nameTOnum;
map<int,string> numTOname;
map<int,int> mp;
map<int,int> wei;

vector<int> maxweight;
vector<Out> out;

bool visit[maxsize] = {0};
int totalweight[maxsize] = {0}; 

bool cmp(Out a,Out b){
	return a.name<b.name;
}

void DFS(int index,int num,int& group_num){
	visit[index] = 1;										//小心初始化错误 
	group_num++;
	node[index].name = numTOname[index];
	node[index].id = index;
	node[index].gang_num = num;

	for(vector<Node> ::iterator it=Adj[index].begin();it!=Adj[index].end();it++){
		node[index].out_weight += it->weight;
		node[it->id].in_weight += it->weight;														

	}
	
	for(vector<Node> ::iterator it=Adj[index].begin();it!=Adj[index].end();it++){
		if(visit[it->id] == 0){
			DFS(it->id,num,group_num);
		}
	}
}

void findboss(int num){
	int max = -1;
	int pos;
	for(int i=0;i<N;i++){
		if(node[i].gang_num == num){
			if(node[i].in_weight+node[i].out_weight > max){
				max = node[i].in_weight+node[i].out_weight;
				pos = i;
			}
		}
	}
	node[pos].is_boss = 1;
}

void total_wei(int num){
	int weight = 0;
	for(int i=0;i<N;i++){
		if(node[i].gang_num == num){
			weight+=node[i].out_weight;
		}		
	}
	wei[num] = weight;
}

int DFStr(int index){
	int num = 0;
	int group_num = 0;
	for(int i=0;i<N;i++){
		if(visit[i] == 0){
			num++;
			DFS(i,num,group_num);
			findboss(num);
			mp[num] = group_num;
			group_num = 0;
			total_wei(num);
		}
	}
	return num;
}




void change(string a,string b,int len){
	if(nameTOnum.find(a) == nameTOnum.end()){//没找到 
	 	nameTOnum[a] = totalnum;
	 	numTOname[totalnum] = a;
	 	totalnum++;
	 	
	}
	 
	if(nameTOnum.find(b) == nameTOnum.end()){//没找到 
	 	nameTOnum[b] = totalnum;
	 	numTOname[totalnum] = b;
	 	totalnum++;
	 	
	}
	
	Adj[nameTOnum[a]].push_back(Node(nameTOnum[b],len));	
	
}

int main(){
	cin>>N>>K;
	int totalnum = 0;
	for(int i=0;i<N;i++){
		string p1,p2;
		int len;
		cin>>p1>>p2>>len;
		change(p1,p2,len);
		
	} 

	int group_num = DFStr(0);

	
	for(int i=0;i<N;i++){
		if(node[i].is_boss == 1 && wei[node[i].gang_num] > K && mp[node[i].gang_num] >2){
			out.push_back(Out(node[i].name,mp[node[i].gang_num]));
		}
	}
	
	sort(out.begin(),out.end(),cmp);
	cout<<out.size()<<endl;
	
	for(vector<Out> :: iterator it = out.begin();it != out.end();it++){
		cout<<it->name<<" "<<it->mem_num<<endl;
	}

	return 0;
} 
