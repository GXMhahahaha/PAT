//A1080. Graduate Adimission
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int quota[100];
int curr[100] = {0};

vector<int> school[100];

struct STU{
	int GE;
	int GI;
	int final;
	int id;
	int choose[5];
	int rank;
}stu[40010];

struct SCH{
	int quota;
	int stuNum = 0;
	vector<int> stu_id;
	int last_Admit = -1;
}sch[110];

bool cmp1(STU a,STU b){
	if(a.final != b.final){
		return a.final > b.final;
	}
	else {
		return a.GE > b.GE;
	}
}

bool cmp2(int a,int b){
	return a<b;
}

int N,M,K;
int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		cin>>sch[i].quota;
	}

	for(int i=0;i<N;i++){
		int _GE,_GI;
		cin>>_GE>>_GI;
		for(int j=0;j<K;j++){
			cin>>stu[i].choose[j];
		}
		stu[i].GE = _GE;
		stu[i].GI = _GI;
		stu[i].final = _GE+_GI;
		stu[i].id = i;

	}
	sort(stu,stu+N,cmp1);

	for(int i=0;i<N;i++){
		if(i>0 && stu[i].final==stu[i-1].final && stu[i].GE==stu[i-1].GE){
			stu[i].rank = stu[i-1].rank;
		}
		else{
			stu[i].rank = i+1;
		}
	}

	for(int i=0;i<N;i++){
		
		for(int j=0;j<K;j++){
			int school_num = stu[i].choose[j];
			int last_Admit = sch[school_num].last_Admit;
			
			if(sch[school_num].stuNum<sch[school_num].quota || (last_Admit!=-1 && stu[i].rank == stu[last_Admit].rank)){
				sch[school_num].stuNum++;
				sch[school_num].stu_id.push_back(stu[i].id);
				sch[school_num].last_Admit = i;
				break;
			}
		}
	}

	
	for(int i=0;i<M;i++){
		sort(sch[i].stu_id.begin(),sch[i].stu_id.end(),cmp2);
	}
	
	for(int i=0;i<M;i++){
		if(sch[i].stu_id.size()>0){
			for(int j=0;j<sch[i].stu_id.size();j++){
				cout<<sch[i].stu_id[j];
				if(j<sch[i].stu_id.size()-1){
					cout<<" ";
				}
			}

		}
		cout<<endl;
		
	}
	
	return 0;
}
