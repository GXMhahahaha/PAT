//有几个PAT
//小心溢出，注意取余的运算法则 
#include <stdio.h>
#include <string.h> 
const int maxsize = 1e5+10;
int leftP[maxsize]={0};
int rightT[maxsize]={0};
char c[maxsize];

int main(){
	scanf("%s",c);
	int len = strlen(c);
	if (c[0] == 'P'){
		leftP[0] = 1;
	}
	if(c[len-1] == 'T'){
		rightT[len-1] = 1;
	}
	for(int i=1;i<len;i++){
		if(c[i]=='P'){
			leftP[i] = leftP[i-1]+1;
		}
		if(c[i]!='P'){
			leftP[i] = leftP[i-1];
		}
		if(c[len-1-i]=='T'){
			rightT[len-1-i] = rightT[len-i]+1;
		}
		if(c[len-1-i]!='T'){
			rightT[len-1-i] = rightT[len-i];
		}
	}
	int total=0;
	for(int i=0;i<len;i++){
		if(c[i]=='A'){
			
			total = (total + leftP[i]*rightT[i])%1000000007;
	
		}
	}	
	printf("%d\n",total);
	
	return 0;
} 
