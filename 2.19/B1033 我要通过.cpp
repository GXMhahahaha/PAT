//B1033 我要通过 
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
	int N;
	cin>>N;
	int num_a = 0,num_b = 0,num_c = 0;
	bool flag = 0;
	for(int i=0;i<N;i++){
		string str;
		cin>>str;
		for(int j=0;j<str.length();){

			while(str[j]!='P'){
				if(str[j] == 'A'){
					num_a++;
					j++;
				}
				else{
					flag = 1;
					break;
				}
			}
			j++;
			if(flag == 1){
				break;
			}
			while(str[j]!='T'){
				if(str[j] == 'A'){
					num_b++;
					j++;
				}
				else{
					flag = 1;
					break;
				}
			}
			j++;
			if(flag == 1){
				break;
			}
			while(j<str.length()){
				if(str[j] == 'A'){
					num_c++;
					j++;
				}
				else{
					flag = 1;
					break;
				}
			}
			
			if(flag == 1){
				break;
			}	      
		}
			
		//一个字符串已经运行完毕； 
		if(flag == 0 && num_c-((num_b-1)*num_a) == num_a && num_b>0){
			printf("YES\n");		
		}
		else{
			printf("NO\n");
		}
		num_a = 0;
		num_b = 0;
		num_c = 0;
		flag = 0;
	}	
	return 0;
} 
