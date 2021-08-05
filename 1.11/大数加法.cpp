#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
struct NUM{
	int num[maxn]={0};
	int len;
}A,B,C;


void change(string s,NUM& X){
	X.len = s.length();
	for(int i=0;i<X.len;i++){
		X.num[i] = s[X.len-i-1]-'0';
	}
}

void add(NUM A,NUM B,NUM& C){
	int temp = max(A.len,B.len);
	int carry = 0;
	int i;
	for(i=0;i<temp;i++){
		int sum = A.num[i] + B.num[i] + carry;
		C.num[i] = sum % 10;
		carry = sum/10;
	}
	if(carry = 1){
		C.num[i] = carry;
		C.len = i;
	}
	else{
		C.len = i-1;
	}
}
int main(){
	string a,b;
	cin>>a>>b;
	change(a,A);
	change(b,B);
	add(A,B,C);
	for(int i=C.len-1;i>=0;i--){
		cout<<C.num[i];
	}	
	


	return 0;
} 
