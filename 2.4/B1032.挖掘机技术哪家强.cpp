//B1032 挖掘机技术哪家强
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int grade[maxn] = {0};
bool exist[maxn] = {0};
int main(){
	int N;
	cin>>N;
	//fill(grade,grade+maxn,-1);
	for(int i=0;i<N;i++){
		int pos;
		int _grade;
		cin>>pos>>_grade;
		exist[pos] = 1;
		grade[pos]+=_grade;
	}
	int id;
	int max = -1;
	for(int i=1;i<maxn;i++){
		if(exist[i] == true && grade[i]>max){
			id = i;
			max = grade[i];	
		}
	}
	cout<<id<<" "<<max;
	return 0;
} 
