//B1026 程序运行时间
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std; 
int main(){
	int C1,C2;
	cin>>C1>>C2;
	int temp = C2-C1;
	double div = 100;
	double re = temp/div;
	int Time = round(re);
	int hour=0,min=0,sec=0;
	while(Time>0){
		if(min==59&&sec==59){
			hour++;
			min = 0;
			sec = 0;
		}
		else if(sec==59){
			min++;
			sec = 0;
		}
		else{
			sec++;
		}
		Time--;
	}	
	printf("%02d:%02d:%02d",hour,min,sec);
	
	
	return 0;
} 
