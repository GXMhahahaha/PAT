//A1152 Google Recruitment
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int L,K;

bool is_Prime(int num){
	if(num == 1 || num == 0){
		return false;
	}
	if(num == 2){
		return true;
	}
	for(int i=2;i<=(int)sqrt(num*1.0);i++){
		if(num%i == 0){
			return false;
		}
	}
	return true;
	
}

int main(){
	cin>>L>>K;
	string str;
	cin>>str;
	for(int i=0;i<=L-K;i++){
		string temp;
		temp = str.substr(i,K);
		int num;
		sscanf(temp.c_str(),"%d",&num);
		if(is_Prime(num)){
			printf("%d\n",num);
			return 0;
		}
	}
	printf("404\n");
	
	return 0;
}
