//A1104 Sum of Number Segments
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	long double ans = 0;
	for(int i=0;i<N;i++){
		long double temp;
		scanf("%llf",&temp);
		ans+=temp*(i+1)*(N-i);
	}
	printf("%.2llf\n",ans);
	return 0;
} 
