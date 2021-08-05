//ËØÊı
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool flag = 1;
	for(int i=2;i<=sqrt(n*1.0);i++){
		if(n%i==0){
			flag = 0;
			break;
		}
	}
	if(flag==0) {
		cout<<"NO";	
	}
	
		else{
			cout<<"YES";
		}
	
	return 0;
} 
