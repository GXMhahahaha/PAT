//Kruscal Ëã·¨
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;
const int maxn = 100;
int N,M;
struct Edge{
	int sou;
	int des;
	int len;
}edge[maxn];

bool cmp(Edge a,Edge b){
	return a.len < b.len;
}

int father[maxn];

int findFather(int x){
	if(x == father[x]){
		return x;
	}
	int y = findFather(father[x]);
	father[x] = y;
	return y;
}


int Kruscal(){
	sort(edge,edge+M,cmp);
	int total = 0;
	for(int i=0;i<M;i++){
		int a,b;
		a = edge[i].sou;
		b = edge[i].des;
		int F1 = findFather(a),F2 = findFather(b);
		if(F1 != F2){
			total+=edge[i].len;
			father[F1] = F2;
		}
	}	
	
	return total;
	
	
}



int main(){
	
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,len;
		cin>>a>>b>>len;
		edge[i].sou = a;
		edge[i].des = b;
		edge[i].len = len;
		
	}
	for(int i=0;i<maxn;i++){
		father[i] = i;
	}
	
	
	cout<<Kruscal()<<endl;
	
	return 0;
}  
