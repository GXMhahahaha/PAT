//¿ìËÙÃÝ
#include <stdio.h>

long long biPow(long long a,long long b,long long c){
	if(b==0){
		return 1;
	}
	if(b%2==1){
		return a*biPow(a,b-1,c)%c;
	}
	if(b%2==0){
		long long temp = biPow(a,b/2,c); 
		return temp*temp%c;
	}
}

int main(){
	long long a;
	long long b;
	long long c;
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld",biPow(a,b,c));
	return 0;
} 
