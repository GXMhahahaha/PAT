//A1078 Hashing
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
const int maxsize = 10010;
bool HashT[maxsize] = {0};
bool is_Prime(int MSize){
	if(MSize == 1){
		return false;
	}
	else{
		for(int i=2;i<=(int)sqrt(1.0*MSize);i++){
			if(MSize%i==0){
				return false;
			}
		}
		return true;
	}
}

int find_Prime(int MSize){
	for(int i=MSize;i<INF;i++){
		if(is_Prime(i)){
			return i;
		}
	}
}



int main(){
	int MSize,N;
	cin>>MSize>>N;
	if(!is_Prime(MSize)){
		MSize = find_Prime(MSize);
	}
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		int step = 0;
		bool flag = 0;
		while(step <= MSize){
			int pos = (num+step*step)%MSize;
			if(HashT[pos] == 0){
				HashT[pos] = 1;
				flag = 1;
				printf("%d",pos);
				if(i<N-1){
					printf(" ");
				}
				break;
			}
			step++;
		}
		if(flag == 0){						//这步可以通过step来判断 不需要非得用flag 
			printf("-");
			if(i<N-1){
				printf(" ");
			}
		}
		
	}
	printf("\n");
		
	return 0;
}
