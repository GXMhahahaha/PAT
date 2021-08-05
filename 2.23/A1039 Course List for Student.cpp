//A1039 Course List for Student			×Ö·û´®hashµÄÊ¹ÓÃ 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200000;
vector<int> HashT[maxn];
int getid(char name[]){
	int id = 0;
	for(int i=0;i<3;i++){
		id = id*26+(name[i]-'A');
	}
	id = id*10+(name[3]-'0');
	return id;
}

bool cmp(int a,int b){
	return a<b;
}

int main(){
	int require_num,course_num;
	cin>>require_num>>course_num;
	for(int i=0;i<course_num;i++){
		int course_id;
		int st_num;
		scanf("%d %d",&course_id,&st_num);
		for(int j=0;j<st_num;j++){
			char name[5];
			scanf("%s",name);
			int st_id = getid(name);
			HashT[st_id].push_back(course_id);
		}
	}
	
	for(int i=0;i<require_num;i++){
		char name[4];
		scanf("%s",name);
		int st_id = getid(name);
		sort(HashT[st_id].begin(),HashT[st_id].end(),cmp);
		printf("%s ",name);
		int size = HashT[st_id].size();
		printf("%d",size);
		if(size>0){
			printf(" ");
		}
		for(int i=0;i<size;i++){
			printf("%d",HashT[st_id][i]);
			if(i<size-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
} 
