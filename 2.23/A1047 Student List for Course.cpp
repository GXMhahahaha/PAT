//A1047 Student List for Course
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxk = 2510;

char name[maxn][5];
vector<int> cour[maxk];

bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int st_num,course_num;
	cin>>st_num>>course_num;
	for(int i=0;i<st_num;i++){
		scanf("%s",name[i]);
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int course_id;
			scanf("%d",&course_id);
			cour[course_id].push_back(i);			
		}

	}
	
	for(int i=1;i<=course_num;i++){
		sort(cour[i].begin(),cour[i].end(),cmp);
		printf("%d %d\n",i,cour[i].size());
		for(int j=0;j<cour[i].size();j++){
			printf("%s\n",name[cour[i][j]]);
		}
	}
	return 0;
}
