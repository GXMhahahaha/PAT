//有几个PAT
//省略了右侧数组的构造 
#include <stdio.h>
#include <string.h> 
const int maxsize = 1e5+10;
int leftP[maxsize]={0};

char c[maxsize];

int main(){
	scanf("%s",c);
	int len = strlen(c);
	int rightTnum = 0;
	if (c[0] == 'P'){
		leftP[0] = 1;
	}


	for(int i=1;i<len;i++){
		if(c[i]=='P'){
			leftP[i] = leftP[i-1]+1;
		}
		if(c[i]!='P'){
			leftP[i] = leftP[i-1];
		}
	}

	int total=0;
	for(int i=len-1;i>=0;i--){
		if(c[i]=='T'){
			rightTnum++;
		}
		if(c[i]=='A'){
			total = (total + leftP[i]*rightTnum)%1000000007;
		}
	}


	printf("%d\n",total);
	
	return 0;
} 
