#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 2010;
int N,K;

struct Edge{
	int id;
	int wei;
	Edge(int _id,int _wei){
		id = _id;
		wei = _wei;
	}
};

int weight[maxn] = {0};
bool visit[maxn] = {0};

vector<Edge> Adj[maxn]; 
map<string,int> NameToNum;
map<int,string> NumToName;
 
map<string,int> out;

void change(string a,string b,int wei){
	if(NameToNum.find(a) == NameToNum.end()){
		int i = NameToNum.size();
		NameToNum[a] = i;
		NumToName[i] = a;
	}

	if(NameToNum.find(b) == NameToNum.end()){
		int i = NameToNum.size();
		NameToNum[b] = i;
		NumToName[i] = b;
	}
	
	weight[NameToNum[a]] += wei;
	weight[NameToNum[b]] += wei;
}

void DFS(int index,int& boss,int& total_wei,int& mem_num,int cur_wei){
	visit[index] = 1;
	mem_num++;
	
	if(weight[index] > cur_wei){
		boss = index;
		cur_wei = weight[index];
	}

	
	for(vector<Edge>::iterator it = Adj[index].begin();it!=Adj[index].end();it++){
		total_wei += it->wei;
		if(visit[it->id] == 0){

			DFS(it->id,boss,total_wei,mem_num,cur_wei);
		}
	}
	
}

void DFStra(int index){

	for(int i=0;i<N;i++){
		int total_wei = 0;
		int boss = 0;
		int mem_num = 0;
		if(visit[i] == 0){
			DFS(i,boss,total_wei,mem_num,-1);
			if(mem_num > 2 && total_wei > K){
				out[NumToName[boss]] = mem_num;
			}
		}
	}
}
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		string a;
		string b;
		int wei;
		cin>>a>>b>>wei;
		change(a,b,wei);
		Adj[NameToNum[a]].push_back(Edge(NameToNum[b],wei));
		
	}
	
	DFStra(0);
	int len = out.size();
	cout<<len<<endl;
	
	for(map<string,int>::iterator it=out.begin();it!=out.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	return 0;
}
