//х╚ееап
#include <stdio.h>
const int maxn=20;
int n;int P[maxn];bool hash[maxn]={0};

void gen(int index){
	if(index==n+1){
		for (int i=1;i<=n;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++){
		if(hash[x]==0){
			P[index]=x;
			hash[x]=1;
			gen(index+1);
			hash[x]=0;
		}
	}
	
}

int main(){
	scanf("%d",&n);
	gen(1);
	
	
	return 0;
} 
