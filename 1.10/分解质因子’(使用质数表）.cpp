//Prime factors
#include <iostream>
#include <math.h>
using namespace std;

struct Prime{
	int val;
	int num;
}prime_f[10];

const int maxn = 1e5; 							    //这个maxn最大为整型上届开根号 
int prime[maxn];
bool _ifchoose[maxn]={0};

int main(){
	int N;
	cin>>N;
	int temp=N;

	//制作质数表(比sqrt(N)小的质数表） 
	int i=0;
	for(int x=2;x<=sqrt(N*1.0);x++){
		if(_ifchoose[x] == 0){
			prime[i++] = x;							//i决定了质数表中有几个质数 
			for(int j=x+x;j<=sqrt(N*1.0);j+=x){		//开根号防止越界 
				_ifchoose[j] = 1;
			}
		}
	} 
	
	int count = i;									//表中一共有count个质数 
	int j = 0;										//用来记录质因子个数； 
	int k = 0;										//记录质数表下标
 

	for(int i=prime[0];k<count;k++,i=prime[k]){
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
	
	if(temp==1){
		cout<<"1=1";
	}
	else{
		cout<<temp<<"=";
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
