//DAG�·
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;
int vexnum,edgenum;
struct Edge{
	int id;
	int len;
};
vector<Edge> Adj[maxn];
int dp[maxn]={0};
vector<int> next0[maxn];
vector<int> re;

int DAG(int i){
	if(dp[i]!=0){
		return dp[i];
	}
	int pos; 
	for(int j=0;j<Adj[i].size();j++){
		if(DAG(Adj[i][j].id) + Adj[i][j].len > dp[i]){
			dp[i] = DAG(Adj[i][j].id) + Adj[i][j].len;
			next0[i].clear();
			next0[i].push_back(Adj[i][j].id);
		}
		else if(DAG(Adj[i][j].id) + Adj[i][j].len == dp[i]){
			next0[i].push_back(Adj[i][j].id);
		}

	}
	return dp[i];
	
}

void pr(int i,int j){
	if(i==j){
		re.push_back(i);
		for(int num=0;num<re.size();num++){
			cout<<re[num]<<" ";
		}
		cout<<endl;
		re.pop_back();
	}
	
	for(int k=0;k<next0[i].size();k++){
		re.push_back(i);
		pr(next0[i][k],j);
		re.pop_back();
	}
}

int main(){
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;i++){
		Edge edge;
		int source;
		cin>>source>>edge.id>>edge.len;
		Adj[source].push_back(edge); 
	}
	cout<<DAG(0)<<endl;
	pr(0,5);
	return 0;
} 
