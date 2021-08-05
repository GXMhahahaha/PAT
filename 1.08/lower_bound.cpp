//lower_bound

#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int *p = lower_bound(a,a+10,3);
	printf("%d",*p);
	
	return 0;
} 
