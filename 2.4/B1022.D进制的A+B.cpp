//B1022 D½øÖÆµÄA+B
#include <iostream>
#include <stack>
using namespace std;

stack<int> res;

int main(){
	int A,B,D;
	cin>>A>>B>>D;
	int sum = A+B;
	do{
		int temp = sum%D;
		sum/=D;
		res.push(temp); 
	}while(sum>0);
	
	while(!res.empty()){
		cout<<res.top();
		res.pop();
	}
	return 0;
} 
