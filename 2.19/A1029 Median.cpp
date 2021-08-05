//A1029 Median
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 1000010;
const int mmaxn = 2000020;
int a[maxn],b[maxn],c[mmaxn];
int N1,N2;
void merge(){
	int i,j,k;
	for(i=0,j=0,k=0;i<N1 && j<N2;k++){
		if(a[i] < b[j]){
			c[k] = a[i++];
		}
		else{
			c[k] = b[j++];
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
	
	cin>>N1;
	for(int i=0;i<N1;i++){
		scanf("%d",&a[i]);
	}
	cin>>N2;
	for(int i=0;i<N2;i++){
		scanf("%d",&b[i]);
	}
	merge();
	cout<<c[(N1+N2-1)/2]<<endl;
	
	return 0;
} 
