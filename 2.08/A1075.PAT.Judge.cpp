#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int N,K,M;
int p[6];				//分值，从1开始数 

const int maxn = 10010;

struct STU{
	int id;
	int p_score[6] = {-2,-2,-2,-2,-2,-2};
	int total_score = 0;
	int Rank;
}stu[maxn],valid[maxn];

bool visited[maxn] = {0};

int perfect(STU a){
	int count = 0;
	for(int i=1;i<=K;i++){
		if(a.p_score[i] == p[i]){
			count++;
		}
	}
	return count;
}

bool cmp(STU a,STU b){
	if(a.total_score!=b.total_score){
		return a.total_score > b.total_score;
	}
	int num1 = perfect(a);
	int num2 = perfect(b);
	if(num1 != num2){
		return num1 > num2;
	}
	else{
		return a.id < b.id;
	}
}

int main(){
	cin>>N>>K>>M;
	for(int i=1;i<=K;i++){
		cin>>p[i];
	}
	
	for(int i=0;i<M;i++){
		int _id,sub,_grade;
		cin>>_id>>sub>>_grade;
		visited[_id] = 1;
		stu[_id].id = _id;
		if(_grade > stu[_id].p_score[sub]){
			stu[_id].p_score[sub] = _grade;
		}
		
	}
	
	int count = 0;
	for(int i=0;i<maxn;i++){
		if(visited[i] == 1){
			
			for(int j=1;j<=K;j++){
				if(stu[i].p_score[j] >=0 ){
					valid[count] = stu[i];
						for(int k=1;k<=K;k++){
							int temp;
							if(valid[count].p_score[k] == -1 || valid[count].p_score[k] == -2){
								temp = 0;
							}
							else{
								temp = valid[count].p_score[k];
							}
							valid[count].total_score+=temp;
						}						
					count++;					
					break;
				}
			}
			
		}
	}
	
	sort(valid,valid+count,cmp);

	valid[0].Rank = 1;
	printf("%d ",valid[0].Rank);
	printf("%05d %d ",valid[0].id,valid[0].total_score);
	for(int j=1;j<=K;j++){
		if(valid[0].p_score[j] == -2){
			printf("-");
		}
		else if(valid[0].p_score[j] == -1){
			printf("0");
		}
		else{
			printf("%d",valid[0].p_score[j]);
		}
		if(j<K){
			printf(" ");
		}
		else if(j==K){
			printf("\n");
		}
	}
	
	for(int i=1;i<count;i++){
		if(valid[i].total_score == valid[i-1].total_score){
			valid[i].Rank = valid[i-1].Rank;
		}
		else{
			valid[i].Rank = i+1;
		}
		
		printf("%d ",valid[i].Rank);
		printf("%05d %d ",valid[i].id,valid[i].total_score);
		
		for(int j=1;j<=K;j++){
			if(valid[i].p_score[j] == -2){
				printf("-");
			}
			else if(valid[i].p_score[j] == -1){
				printf("0");
			}
			else{
				printf("%d",valid[i].p_score[j]);
			}
			if(j<K){
				printf(" ");
			}
			else if(j==K){
				printf("\n");
			}
		}
		
	}
	
	
	return 0;
}
