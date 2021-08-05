#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
const int maxn = 20010;
struct STU{
	int id;
	int C;
	int M;
	int E;
	int A;
}stu[maxn];

struct STU_C{
	int id;
	int C;
	int rank = 1;
}stu_C[maxn];


struct STU_M{
	int id;
	int M;
	int rank = 1;
}stu_M[maxn];


struct STU_E{
	int id;
	int E;
	int rank = 1;
}stu_E[maxn];


struct STU_A{
	int id;
	int A;
	int rank = 1;
}stu_A[maxn];

void Init(int num){
	for(int i=0;i<num;i++){
		stu_C[i].id = stu[i].id;
		stu_M[i].id = stu[i].id;
		stu_E[i].id = stu[i].id;
		stu_A[i].id = stu[i].id;
		
		stu_C[i].C = stu[i].C;
		stu_M[i].M = stu[i].M;
		stu_E[i].E = stu[i].E;
		stu_A[i].A = stu[i].A;
	}
}

bool cmp_C	(STU_C a,STU_C b) {
	return a.C>b.C;
}

bool cmp_M	(STU_M a,STU_M b) {
	return a.M>b.M;
}

bool cmp_E	(STU_E a,STU_E b) {
	return a.E>b.E;
}

bool cmp_A	(STU_A a,STU_A b) {
	return a.A>b.A;
}

void _Rank(int num){
	for(int i=1;i<num;i++){
		if(stu_C[i].C == stu_C[i-1].C){
			stu_C[i].rank = stu_C[i-1].rank;
		}
		else if(stu_C[i].C != stu_C[i-1].C){
			stu_C[i].rank = i + 1;
		}
		
		if(stu_M[i].M == stu_M[i-1].M){
			stu_M[i].rank = stu_M[i-1].rank;
		}
		else if(stu_M[i].M != stu_M[i-1].M){
			stu_M[i].rank = i + 1;
		}
		
		if(stu_E[i].E == stu_E[i-1].E){
			stu_E[i].rank = stu_E[i-1].rank;
		}
		else if(stu_E[i].E != stu_E[i-1].E){
			stu_E[i].rank = i + 1;
		}
		
		if(stu_A[i].A == stu_A[i-1].A){
			stu_A[i].rank = stu_A[i-1].rank;
		}
		else if(stu_A[i].A != stu_A[i-1].A){
			stu_A[i].rank = i + 1;
		}
	}
}


int main(){
	cin>>N>>M;
	int num = 0;
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].C,&stu[i].M,&stu[i].E);
		stu[i].A = (stu[i].id+stu[i].C+stu[i].M+stu[i].E)/3;
		num++;
	}
	Init(num);
	sort(stu_C,stu_C+num,cmp_C);
	sort(stu_M,stu_M+num,cmp_M);
	sort(stu_E,stu_E+num,cmp_E);
	sort(stu_A,stu_A+num,cmp_A);
	
	_Rank(num);	
			
	for(int i=0;i<M;i++){
		int pai = 20010;
		char subject;	
	
		int _id;
		scanf("%d",&_id);
		bool flag = false;
		for(int k=0;k<num;k++){
			if(_id == stu_A[k].id){
				if(pai>stu_A[k].rank){
					pai = stu_A[k].rank;
					subject = 'A';
					flag = true;
					break;
				}
			}
		}
		if(flag == false){
			cout<<"N/A"<<endl;
			continue;
		}
		
		for(int k=0;k<num;k++){
			if(_id == stu_C[k].id){
				if(pai>stu_C[k].rank){
					pai = stu_C[k].rank;
					subject = 'C';
					break;
				}
			}
		}		
		
		for(int k=0;k<num;k++){
			if(_id == stu_M[k].id){
				if(pai>stu_M[k].rank){
					pai = stu_M[k].rank;
					subject = 'M';
					break;
				}
			}
		}
		
		for(int k=0;k<num;k++){
			if(_id == stu_E[k].id){
				if(pai>stu_E[k].rank){
					pai = stu_E[k].rank;
					subject = 'E';
					break;
				}
			}
		}
		
		printf("%d %c\n",pai,subject);
	}
	return 0;
} 
