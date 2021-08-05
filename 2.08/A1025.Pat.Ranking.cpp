#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct STU{
	string id;
	int grade;
	int place;
	int local_rank;
	int total_rank;
}stu[30010];

bool cmp(STU a,STU b){
	if(a.grade!=b.grade)
		return a.grade>b.grade;
	else
		return a.id<b.id;
}

void Rank(int on,int off){
	stu[on].local_rank = 1;
	for(int i=on+1;i<off;i++){
		if(stu[i].grade == stu[i-1].grade){
			stu[i].local_rank = stu[i-1].local_rank;
		}
		else{
			stu[i].local_rank = i-on+1;
		}
	}
}

int main(){
	int N;
	cin>>N;
	int pos[N+1]={0};
	for(int i=0;i<N;i++){
		int K;
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>stu[j+pos[i]].id>>stu[j+pos[i]].grade;
			stu[j+pos[i]].place = i+1;
		}
		pos[i+1] = pos[i] + K;										//pos[0]是第一段起始位置，pos[1]第二段。。。。pos[N] N+1段； 
	}
	
	for(int i=0;i<N;i++){
		sort(stu+pos[i],stu+pos[i+1],cmp);
		Rank(pos[i],pos[i+1]);
	}
	sort(stu+pos[0],stu+pos[N],cmp);
	stu[0].total_rank = 1;
	
	cout<<pos[N]<<endl;
	cout<<stu[0].id<<" "<<stu[0].total_rank<<" "<<stu[0].place<<" "<<stu[0].local_rank<<endl;
	
	for(int i=1;i<pos[N];i++){
		cout<<stu[i].id<<" ";
		if(stu[i].grade == stu[i-1].grade){
			stu[i].total_rank = stu[i-1].total_rank;
		}
		else{
			stu[i].total_rank = i+1;
		}
		cout<<stu[i].total_rank<<" "<<stu[i].place<<" "<<stu[i].local_rank<<endl;
	}

	return 0;
}
