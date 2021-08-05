//B1046 »®È­
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int N;
	int numa=0,numb=0;
	cin>>N;
	for(int i=0;i<N;i++){
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		if(a2==a1+b1&&b2!=a1+b1){
			numb++;
		}
		else if(a2!=a1+b1&&b2==a1+b1){
			numa++;
		}
	}
	cout<<numa<<" "<<numb;
	return 0;
} 
