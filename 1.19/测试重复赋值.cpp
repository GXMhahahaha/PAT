//测试反复赋值会不会越界

#include <iostream>
using namespace std;


int main(){
	
	for(int i=0;i<1e10;i++){
		int num = i;
		//cout<<&num<<" "<<num<<endl;
		int a=0,b=1;
		int c=a+b; 
	}
	
	return 0;
} 
