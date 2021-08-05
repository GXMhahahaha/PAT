//A1028.List sorting
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct STU{
	int id;
	string name;
	int grade;
}stu[maxn];

bool cmp1(STU a,STU b){
	return a.id<b.id;
}

bool cmp2(STU a,STU b){
	if(a.name!=b.name)
		return a.name<b.name;
	
	else
		return a.id<b.id;
	

}


bool cmp3(STU a,STU b){
	if(a.grade!=b.grade)
		return a.grade<b.grade;
	
	else
		return a.id<b.id;
	
}
int main(){
	int N,C;
	cin>>N>>C;
	for(int i=0;i<N;i++){
		cin>>stu[i].id>>stu[i].name>>stu[i].grade;
	}
	

	
	if(C==1){
		sort(stu,stu+N,cmp1);
		for(int i=0;i<N;i++){
			printf("%06d ",stu[i].id);
			cout<<stu[i].name<<" "<<stu[i].grade<<endl; 
		}
	}
	
	else if(C==2){
		sort(stu,stu+N,cmp2);
		for(int i=0;i<N;i++){
			printf("%06d ",stu[i].id);
			cout<<stu[i].name<<" "<<stu[i].grade<<endl; 
		}
	}
	
	else if(C==3){
		sort(stu,stu+N,cmp3);
		for(int i=0;i<N;i++){
			printf("%06d ",stu[i].id);
			cout<<stu[i].name<<" "<<stu[i].grade<<endl; 
		}
	}
	return 0;
}
