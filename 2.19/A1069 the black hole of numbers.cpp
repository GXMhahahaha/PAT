//A1069 the black hole of numbers 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

bool cmp1(char a,char b){
	return a>b;
}

bool cmp2(char a,char b){
	return a<b;
}

int change(string str){
	int ans;
	sscanf(str.c_str(),"%d",&ans);
	return ans;
}

int main(){
	int num;
	cin>>num;
	string str;
	char temp[10];
	sprintf(temp,"%04d",num);
	str = temp;
	int ans = 0;
	while(ans!=6174){
		sort(str.begin(),str.end(),cmp1);
		int num_a = change(str);
		sort(str.begin(),str.end(),cmp2);
		int num_b = change(str);
		ans = num_a - num_b;
		if(ans == 0){
			printf("%04d - %04d = %04d\n",num_a,num_b,ans);
			break;
		}
		else{
			printf("%04d - %04d = %04d\n",num_a,num_b,ans);
			char temp[10];
			sprintf(temp,"%04d",ans);
			str = temp;
		}		
	}


	
	return 0;
}
