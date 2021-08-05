//Õÿ∆À≈≈–Ú
#include <iostream>
#include <queue>
using namespace std;

int vexnum,edgenum;
const int maxn = 1e5;
vector<int> Adj[maxn];

struct Node{
	int id;
	int indegree = 0;
}node[maxn];

vector<int> result;

bool Topo(){
	int num = 0;
	int pos;
	bool flag = false;
	for(int i=0;i<vexnum;i++){
		if(node[i].indegree==0){
			flag = true;
			pos = i;
			break;
		}
	}
	if(flag == false){
		return false;
	}
	
	queue<int> q;
	q.push(pos);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		num++;
		result.push_back(a);
		for(int i=0;i<Adj[a].size();i++){
			int temp = Adj[a][i];
			node[temp].indegree--;
			if(node[temp].indegree == 0){
				q.push(temp);
			}
		}
		
		
	}
	if(num == vexnum)
		return true;
	else{
		return false;;
		
	}
}



int main(){
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
		int u,v;
		cin>>u>>v;
		Adj[u].push_back(v);
		node[v].indegree++;
	}
	bool flag = Topo();
	if(flag == true){
		cout<<"True"<<endl;
		for(int i=0;i<result.size();i++){
			cout<<result[i];
		}
	}
	else{
		cout<<"False";
	}
	
	return 0;
} 
