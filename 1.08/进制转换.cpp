//����ת�� 
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
int decimal(long long num,int N){
	int res = 0, pow = 1;
	while(num!=0){
		res+=(num%10)*pow;
		num/=10;
		pow*=N;
	}
	return res;
	
}

void turn(long long num,int N){
	do{
		s.push(num%N+'0');
		num/=N;
		
	}while(num!=0);
	
}
int main(){
	int N1,N2;
	long long num;
	cout<<"��������"<<endl;
	scanf("%lld",&num);
	cout<<"����ԭʼ���ƺ�ת������"<<endl;
	scanf("%d %d",&N1,&N2);
	int temp = decimal(num,N1); 
	turn(temp,N2);

	while(!s.empty()){
		printf("%c",s.top());
		s.pop();
	}
		
	
	return 0;
}
