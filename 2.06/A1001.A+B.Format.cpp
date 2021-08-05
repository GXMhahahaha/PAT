//A1001 A+B Format
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main(){
	int a,b;
	cin>>a>>b;
	int sum = a+b;
	int flag = false;
	if(sum < 0){
		sum = -sum;
		flag = true;
		
	}
	int i=1;
	do{
		s.push(sum%10+'0');
		sum/=10;
		if(i%3==0&&sum>0){
			s.push(',');
		}
		i++;
	}while(sum>0);
	
	if(flag == true){
		s.push('-');
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
} 
