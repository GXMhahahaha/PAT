//A1015 Reversible Primes
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

bool is_Prime(int num){
	if(num==1){
		return false;
	}
	bool flag = true;
	for(int i=2;i<=(int)sqrt(1.0*num);i++){
		if(num%i==0){
			flag = false;
			break;
		}
	}
	return flag;
}

string numToradix(int num,int radix){
	string ans;
	do{
		ans+=(num%radix)+'0';
		num/=radix;
	}while(num>0);
	return ans;
}

int radixTonum(string change,int radix){

	int mul = 1;
	int ans = 0; 
	for(int i=change.length()-1;i>=0;i--){
		ans += (change[i]-'0')*mul;
		mul*=radix;
	}
	return ans;
}

int main(){
	int num,radix;
	while(1){
		scanf("%d",&num);
		if(num < 0){
			break;
		}
		scanf("%d",&radix);

		if(!is_Prime(num)){
			printf("No\n");
			continue;
		}
		string change = numToradix(num,radix);
		int rev = radixTonum(change,radix);
		if(is_Prime(rev)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}
