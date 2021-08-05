//B1023.组个最小数
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int num[51];					//第一个数没用 

int count1[10];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int total=0;
	
	for(int i=0;i<10;i++){
		cin>>count1[i];
	}
	
	for(int i=1;i<10;i++){
		if(count1[i]>0){
			cout<<i;
			count1[i]--;
			break;
		}
	}
	
	for(int i=0;i<10;i++){
		while(count1[i]>0){
			cout<<i;
			count1[i]--;
		}
	}

	
	
	
	return 0;
} 
