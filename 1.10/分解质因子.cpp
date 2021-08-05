//Prime factors
#include <iostream>
#include <math.h>
using namespace std;

struct Prime{
	int val;
	int num;
}prime_f[10];

const int maxn = 1e5;
int prime[maxn];
bool _ifchoose[maxn]={0};

int main(){
	int N;
	cin>>N;
	int init_N = N;
	
	int j=0;
	 
	for(int i=2;i<=sqrt(init_N*1.0);i++){
		if(N%i == 0){
			prime_f[j].val = i;
			prime_f[j].num = 1;
			N/=i;
			j++;
			
			while(N%i == 0){
				prime_f[j-1].num++;
				N/=i;
			}
		}
	
		if(N==1) break;
			
	}
	if(N!=1){
		prime_f[j].val = N;
		prime_f[j].num = 1;
		j++; 
	}
	
	
	
	if(init_N==1){
		cout<<"1=1";
	}
	else{
		cout<<init_N<<"=";
	}
	for(int i=0;i<j;i++){
		if(prime_f[i].num!=1){
			cout<<prime_f[i].val<<"^"<<prime_f[i].num;
		}
		else{
			cout<<prime_f[i].val;
		}
		if(i!=j-1){
			cout<<"*";
		}
		
	} 	
	return 0;
}
