//A+BºÍC
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		long long A,B,C;
		scanf("%lld %lld %lld",&A,&B,&C);
		if(A+B>C){
			printf("Case #%d:true\n",i+1);
		}
		else{
			printf("Case #%d:false\n",i+1); 
		}
	}
	return 0;
} 
