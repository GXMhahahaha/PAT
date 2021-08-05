//A1064 Complete Binary Search Tree
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int N;
vector<int> ori;
int node[maxn];
int i=0;

void inorder(int index){
	if(index > N){
		return;
	}
	inorder(index*2);
	node[index] = ori[i++];
	inorder(index*2+1);
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		ori.push_back(temp);
	}
	sort(ori.begin(),ori.end());
	inorder(1);
	for(int i=1;i<=N;i++){
		printf("%d",node[i]);
		if(i<=N-1){
			printf(" ");
		}
	}
	cout<<endl;
	return 0;
} 
