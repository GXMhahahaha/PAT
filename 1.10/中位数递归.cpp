//递归求中位数
//这种解法有不知名的bug 
#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 200010;  

int a[maxn];
int b[maxn];

int find(int a[],int b[],int low1,int low2,int high1,int high2){
	int mid1,mid2;
	while(high1>low1||high2>low2){
		mid1 = (low1+high1)/2;
		mid2 = (low2+high2)/2;
		if(a[mid1]==b[mid2]){
			return a[mid1];
		}
		if(a[mid1]>b[mid2]){
			if((low2+high2)%2==1){
				low2 = mid2 + 1;
				high1 = mid1;
			}
			else{
				low2 = mid2;
				high1 = mid1;
			}
		}
		else if(a[mid1]<b[mid2]){
			if((low1+high1)%2==1){
				low1 = mid1 + 1;
				high2 = mid2;
			}
			else{
				low1 = mid1;
				high2 = mid2;
			}
		}	
	}
	return (a[low1]<b[low2]) ? a[low1]:b[low2];
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


	cout<<find(a,b,0,0,N1-1,N2-1)<<endl;
	return 0;
} 
