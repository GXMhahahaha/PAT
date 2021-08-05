//¹¹Ôìº¯Êı²âÊÔ
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct STU{
	int grade;
	int id[10];
	STU(){
		grade = 100;
		fill(id,id+10,3);
	}
	STU(int _grade){
		grade = _grade;
		
	}
}stu[10];


int main(){
	for(int i=0;i<10;i++){
		cout<<stu[i].grade<<" "<<stu[i].id[2]<<endl;
	}
	stu[3] = STU(96);
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<stu[i].grade<<" "<<stu[i].id[2]<<endl;
	}
	
	return 0;
} 
