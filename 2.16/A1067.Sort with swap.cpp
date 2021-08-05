#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main(){
	int N;
	cin>>N;
	int chaos = 0;
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		pos[num] = i;
		if(num!=i){
			chaos++;
		}
	}
	
	int k = 1;
	int swaptimes = 0;
	while(chaos>0){
		if(pos[0] == 0){
			while(k<N){
				if(pos[k]!=k){
					swap(pos[0],pos[k]);
					chaos++;
					swaptimes++;
					break;
				}
				else{
					k++;
				}
			}
		}
		
		else{
			swap(pos[0],pos[pos[0]]);
			swaptimes++;
			chaos--;
			if(pos[0] == 0){
				chaos--;
			}
		
		}
	}
	cout<<swaptimes<<endl;
	
	
	
	return 0;
}
