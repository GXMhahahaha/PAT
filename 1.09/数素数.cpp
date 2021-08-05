#include <iostream>
#include <stdio.h>

using namespace std;

const int pmax = 2e5;//素数能去到的最大范围 
const int maxn = 1e4;//数组下标的最大范围 
int p[maxn];
bool q[pmax] = {0};

int main(){
	int M,N;
	cin>>M>>N;
	p[0]=2;
	q[2]=1;
	int count=2,i=1;
	while(count<=pmax){
		q[count] = 1;
		count=2*(i++);
	}
	int j=1;
	for(int i=3;i<pmax;i++){
		if(q[i]==0){
			p[j++]=i;
			int count = i;int pow=1;
			while(count<=pmax){
			q[count] = 1;
			count=i*(pow++);
	}
		}
		if(j==N){
			break;
		}
	}
	int k=1;
	for(int i=M-1;i<=N-1;i++){
		if(k%10!=0){
			cout<<p[i];
			if(i!=N-1){
				cout<<" ";
			}	
		}
		else{
			cout<<p[i]<<endl;
		}
		k++;
		
	}
	
	return 0;
}
