//B1007 ËØÊı¶Ô²ÂÏë 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	int pre = 2,next = 3;
	int count = 0;
	
	for(int i=5;i<=N;i++){
		bool flag = false;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j == 0){
				flag = 1;
				break;
			}
		}
		if(flag == false){
			pre = next;
			next = i;
			if(next-pre == 2){
				count++;
			}
		}
	}
	cout<<count<<endl;
	
	
	return 0;
} 
