//find()函数时间复杂度为n 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *p = find(a,a+10,0); 
	cout<<p-a<<endl;
	
	
	return 0;
}
