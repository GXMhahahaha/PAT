//A1107 Social Clusters
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int course[maxn] = {0};
int father[maxn];
int isRoot[maxn] = {0};

void Init(){
	for(int i=0;i<maxn;i++){
		father[i] = i;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int findfather(int x){
	if(father[x] == x){
		return x;
	}
	else{
		int F = findfather(father[x]);
		father[x] = F;
		return F;
	}
}

void Union(int a,int b){
	int f1 = findfather(a);
	int f2 = findfather(b);
	if(f1 != f2)
		father[f1] = f2;
}

int main(){
	int N;
	cin>>N;
	Init();
	for(int i=0;i<N;i++){
		int hobbynum;
		scanf("%d: ",&hobbynum);
		for(int j=0;j<hobbynum;j++){
			int temp;
			scanf("%d",&temp);
			if(course[temp] != 0){
				Union(i+1,course[temp]);
			}
			course[temp] = i+1;
		}
	}

	for(int i=0;i<N;i++){
		isRoot[findfather(i+1)]++;
	}
	sort(isRoot,isRoot+maxn,cmp);
	
	int count = 0;
	for(int i=0;i<maxn;i++){
		if(isRoot[i] != 0){
			count++;
		}
		else{
			break;
		}
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		printf("%d",isRoot[i]);
		if(i<count-1){
			printf(" ");
		}
	}
	cout<<endl;
	return 0;
}
