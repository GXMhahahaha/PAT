#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct STU{
	string name;
	char sex;
	int age;
	string id;
	STU(){};
	STU(string name1,char sex1,int age1,string id1){
		name = name1;
		sex = sex1;
		age = age1;
		id = id1;
	}
}stu[100]; 

int main(){
	stu[0] = STU("BILL",'M',21,"220103199812142714");
	stu[1] = STU("LOLI",'F',22,"313511054613153056");
	queue<STU> student;
	student.push(stu[0]);
	student.push(stu[1]);
	
	
	cout<<student.front().age<<endl<<student.back().id<<endl; 
	
	
	return 0;
}
