#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h> 
using namespace std;
const int maxn=10010;
int p[maxn]={0}; 
int main(){
	p[0] = 2;
	int i = 1;
	int num = 3; 
	while(i < 10000){
		bool flag = 1;
		for(int x=2;x<=sqrt(num*1.0);x++){
			if(num%x==0){
				flag = false;
				break;
			}
		}
		if(flag==true){
			p[i++] = num;
		}
		num++;
	}
	
//	cout<<p[0]<<" "<<p[1];
	for(int i=0;i<10000;i++)
     cout<<p[i]<<" "<<endl;

	
	
	return 0;
}
