//A1083. List Grades
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 1e5;
struct STU{
	string name;
	string ID;
	int grade;
}stu[maxn];

bool cmp(STU a,STU b){
	return a.grade > b.grade;
}


int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>stu[i].name>>stu[i].ID>>stu[i].grade;
		
	}
	
	sort(stu,stu+N,cmp);
	int low,high;
	cin>>low>>high;
	
	bool flag = false;
	for(int i=0;i<N;i++){
		if(stu[i].grade>=low && stu[i].grade <=high){
			cout<<stu[i].name<<" "<<stu[i].ID<<endl;
			flag = true;
		}
	}
	if(flag == false){
		cout<<"NONE"<<endl;
	}
	
	return 0;
}
