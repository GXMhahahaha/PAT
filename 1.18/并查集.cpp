//并查集，好朋友
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxsize = 1e5;

int father[maxsize];
bool is_root[maxsize];

void Init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i; 
		is_root[i] = false;
	}
	
}

int find_father(int x){
	if(father[x] == x){
		return x;
	}
	else{
		int f = find_father(father[x]);
		father[x] = f;
		return f;
	}
}

Union(int a,int b){
	int father_a = find_father(a);
	int father_b = find_father(b);
	
	if(father_a != father_b){
		father[father_a] = father_b;
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	Init(n);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		Union(a,b);
	}
	
	
	for(int i=1;i<=n;i++){
		is_root[find_father(i)] = true;
	}
	
	int cal = 0;
	for(int i=1;i<=n;i++){
		if(is_root[i] == 1){
			cal++;
		}
	}

	cout<<cal<<endl;
	
	return 0;
} 
