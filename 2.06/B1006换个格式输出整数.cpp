//B1006 换个格式输出整数
#include <iostream>
#include <string>

using namespace std;

int main(){
	int num;
	cin>>num;
	int bai,shi,ge;
	bai = num/100;
	num%=100;
	shi = num/10;
	num%=10;
	ge = num;
	for(int i=0;i<bai;i++){
		cout<<"B";
	}
	for(int i=0;i<shi;i++){
		cout<<"S";
	}
	for(int i=1;i<=ge;i++){
		cout<<i;
	}
	return 0;
} 
