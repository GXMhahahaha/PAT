//中位数 
#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 200010;  

int a[maxn];
int b[maxn];
int c[maxn*2];
void mergesort(int a[],int b[],int N1,int N2){
	int i = 0,j = 0,k = 0;
	while(i<N1 && j<N2){
		if(a[i]<b[j]){
			c[k++] = a[i];
			i++;
		}
		else{
			c[k++] = b[j];
			j++;
		}
	}
	while(i<N1){
		c[k++] = a[i++];
	}
	while(j<N2){
		c[k++] = b[j++];
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

	mergesort(a,b,N1,N2);
	
	cout<<c[(N1+N2-1)/2]<<endl;
	return 0;
} 
