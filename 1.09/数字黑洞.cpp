#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int a[4];
	int i = 0;
	int temp = N;	
	while(i<4){
		a[i] = N%10;
		N/=10;
		i++;
	}//a[0]´æ·Å¸öÎ»
	if(a[0]==a[1]&&a[0]==a[2]&&a[0]==a[3]){
		printf("%04d - %04d = 0000\n",temp,temp);
	}
	else{
		do{
		while(i<4){
			a[i] = N%10;
			N/=10;
			i++;
		}
		i = 0;	
		sort(a,a+4);
		int less = 0,more = 0;
		int pow=1;
		for(int i=0;i<4;i++){
			more+=a[i]*pow;
			pow = pow*10;
		
		}	 
		pow = 1;
		for(int i=3;i>=0;i--){
			less+=a[i]*pow;
			pow = pow*10;
		
		}
	
		N = more-less; 
		printf("%04d - %04d = %04d\n",more,less,N);	
		}while(N!=6174);

	}
	
	
	
	return 0;
}
