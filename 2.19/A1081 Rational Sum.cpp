//A1081 Rational Sum
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long LL;
int integ = 0;
int num = 0,deno = 1;

LL gcd(LL a,LL b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}

void Add(int temp_num,int temp_deno){
	LL fenzi;
	LL fenmu;
	fenzi = num*temp_deno+deno*temp_num;
	fenmu = deno*temp_deno;
	LL factor = gcd(abs(fenzi),abs(fenmu));
	fenzi/=factor;
	fenmu/=factor;
	int temp_integ = fenzi/fenmu;
	
	num = fenzi%fenmu;
	deno = fenmu;
	integ+=temp_integ;
}

int main(){
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++){
		int temp_num;
		int temp_deno;
		scanf("%d/%d",&temp_num,&temp_deno);
		Add(temp_num,temp_deno);
		
	}
	
	if(integ!=0){
		cout<<integ;
		if(num!=0){
			cout<<" "<<abs(num)<<"/"<<deno;
		}
		cout<<endl;	
	}
	else{
		if(num == 0){
			cout<<"0"<<endl;
		}
		else{
			cout<<abs(num)<<"/"<<deno<<endl;
		}
	}

	return 0;
}
