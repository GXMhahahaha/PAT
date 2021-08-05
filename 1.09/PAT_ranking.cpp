#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std; 
struct STU{
	char id[14];
	int grade;
	int rank;
	int loc;
}stu[30000];

bool cmp(STU stu1,STU stu2){
	if(stu1.grade!=stu2.grade)
		return stu1.grade>stu2.grade;
	else{
		return strcmp(stu1.id,stu2.id)<0;//好好体会这句话 
	}
}

void _rank(int first,int last){
	stu[first++].rank = 1;
	int r=1;
	while(first<last){
		if(stu[first].grade < stu[first-1].grade){
			stu[first].rank = ++r;
		}
		else{
			stu[first].rank = stu[first-1].rank;
			r++;
		}
		first++;
	}
}

int main(){
	int N;
	scanf("%d",&N);
	int head = 0;
	int j = 0;		//一直记录数组位置 
	int total = 0;
	
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);
		for(int cal=0;cal<k;cal++){
			scanf("%s %d",stu[j].id,&stu[j].grade);
			stu[j].loc = i+1;
			j++;
			total++;
		}
		sort(stu+head,stu+j,cmp);
		_rank(head,j);
		head = j;
	}
	

	sort(stu+0,stu+total,cmp);
	cout<<total<<endl;
	int first =0 ,last = total;
	int r = 1;
	int temp = r;
	printf("%s %d %d %d\n",stu[0].id,r,stu[0].loc,stu[0].rank);
	first++;
	
	//计算排名
	//另一种方法：当前考生与上一名考生成绩不同时，他的排名等与当前遍历人数加1
	 
	while(first<last){
		if(stu[first].grade < stu[first-1].grade){
			printf("%s %d %d %d\n",stu[first].id,++r,stu[first].loc,stu[first].rank);
			temp = r;
		}
		else{
			printf("%s %d %d %d\n",stu[first].id,temp,stu[first].loc,stu[first].rank);
			r++;
		}
		first++;
	}
	return 0;
	
}

