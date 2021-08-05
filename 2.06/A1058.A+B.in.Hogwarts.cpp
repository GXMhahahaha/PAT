//A+B in Hogwarts
#include <iostream>
using namespace std;

int main(){
	int GA1,SI1,KN1,GA2,SI2,KN2;
	scanf("%d.%d.%d",&GA1,&SI1,&KN1);
	scanf("%d.%d.%d",&GA2,&SI2,&KN2);
	int GA,SI,KN;
	int carry = 0;
	KN = (KN1+KN2)%29;
	carry = (KN1+KN2)/29;
	SI = (SI1+SI2+carry)%17;
	carry = (SI1+SI2+carry)/17;
	GA = GA1+GA2+carry;
	cout<<GA<<"."<<SI<<"."<<KN;
	 
	return 0;
} 
