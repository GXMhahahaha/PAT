//哈希哈希哈希 
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 2020;

struct STU{
	int id;
	int grade[4];				//A,C,M,E 
}stu[maxn];
int now;					//本题使用id的哈希速度会快一些

int Rank[1000000][4] = {0}; 

char c[4] = {'A','C','M','E'};

bool cmp(STU a,STU b){
	return a.grade[now] > b.grade[now];
	
}

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0] = stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];
	}
	
	for(int i=0;i<4;i++){
		now = i;
		sort(stu,stu+N,cmp);
		Rank[stu[0].id][i] = 1;
		for(int j=1;j<N;j++){

			if(stu[j].grade[i] == stu[j-1].grade[i]){
				Rank[stu[j].id][i] = Rank[stu[j-1].id][i];
			}
			else{
				Rank[stu[j].id][i] = j + 1;
			}
		}
	}
	
	for(int i=0;i<M;i++){
		int _id;
		scanf("%d",&_id);
		int min_rank = 20010;
		char sub;

		if(Rank[_id][0] == 0){
			cout<<"N/A"<<endl;		
		}
		else{
			for(int j=0;j<4;j++){
				if(min_rank > Rank[_id][j]){
					min_rank = Rank[_id][j];
					sub = c[j];
				}
			}
			printf("%d %c\n",min_rank,sub);
		}			
	}

	
	return 0;
} 
