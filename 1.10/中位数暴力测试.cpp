//中位数暴力 
//内存并不会越界 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200010;  

int a[maxn];
int b[maxn];
int c[maxn*2];
void merge(int a[],int b[],int N1,int N2){
	int i = 0;
	for(int i=0;i<N1+N2;i++){
		if(i<N1){
			c[i] = a[i];
		}
		if(i>=N1&&i<N1+N2){
			c[i] = b[i-N1];
		}
		
	}
	
}

int main(){
	
	//输入 
	int N1,N2;
	cin>>N1;
	
	for(int i=0;i<N1;i++){
		scanf("%d",&a[i]);
	}
	cin>>N2;
	for(int i=0;i<N2;i++){
		scanf("%d",&b[i]);
	}
 	merge(a,b,N1,N2); 
	sort(c,c+N1+N2);
	cout<<c[(N1+N2-1)/2]<<endl;
	return 0;
} 
