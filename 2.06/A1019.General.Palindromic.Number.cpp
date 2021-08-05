//General Palindromic Number
#include <stdio.h>
#include <iostream>

using namespace std;

int num[40];

int main(){
	int N,b;
	cin>>N>>b;
	int size = 0;
	do{
		int temp;
		temp = N%b;
		num[size++] = temp;
		N/=b;
	}while(N>0);
	
	bool flag = true;
	for(int i=0;i<size;i++){
		if(num[i]!=num[size-1-i]){
			flag = false;
			break;
		}
	}
	if(flag == true){
		cout<<"Yes"<<endl;
	}
	else if(flag == false){
		cout<<"No"<<endl;
	}
	for(int i=size-1;i>=0;i--){
		cout<<num[i];
		if(i>0){
			cout<<" ";
		}
	}
	return 0;
}
