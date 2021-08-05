//B1037 ÔÚ»ô¸ñÎÖ×ÈÕÒÁãÇ®
#include <iostream>
#include <string>
//#include <string.h>
using namespace std;
char c[20];

int change1(int a,int b,int c){
	return (c+b*29+a*17*29);
}

void sub(int a,int b){
	int diff = a-b;
	int GA,SI,KN;
	GA = diff/(17*29);
	diff%=(17*29);
	SI = diff/29;
	diff%=29;
	KN = diff;
	sprintf(c,"%d.%d.%d",GA,SI,KN);

}
int main(){
	int Ga1,Si1,Kn1;
	int Ga2,Si2,Kn2;
	scanf("%d.%d.%d",&Ga1,&Si1,&Kn1);
	scanf("%d.%d.%d",&Ga2,&Si2,&Kn2);
	int temp1 = change1(Ga1,Si1,Kn1);
	int temp2 = change1(Ga2,Si2,Kn2);
	if(temp1>temp2){
		cout<<"-";
		sub(temp1,temp2);
		printf("%s",c);
	}
	else if(temp1<=temp2){
		sub(temp2,temp1);
		printf("%s",c);
	} 

	
	return 0;
} 
