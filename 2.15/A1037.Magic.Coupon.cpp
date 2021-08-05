//A1037 Magic.Coupon
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int NC_P[maxn],NC_N[maxn],NP_P[maxn],NP_N[maxn];

bool cmp1(int a,int b){
	return a>b;
}

bool cmp2(int a,int b){
	return a<b;
} 
int main(){
	int N1,N2;
	int p1=0,p2=0,n1=0,n2=0;
	
	cin>>N1;
	for(int i=0;i<N1;i++){
		int temp;
		scanf("%d",&temp);
		if(temp>0){
			NC_P[p1++] = temp;
		}
		else if(temp<0){
			NC_N[n1++] = temp;
		}
	}
	
	cin>>N2; 
	for(int i=0;i<N2;i++){
		int temp;
		scanf("%d",&temp);
		if(temp>0){
			NP_P[p2++] = temp;
		}
		else if(temp<0){
			NP_N[n2++] = temp;
		}
	}
	
	sort(NC_P,NC_P+p1,cmp1);
	sort(NC_N,NC_N+n1,cmp2);
	sort(NP_P,NP_P+p2,cmp1);
	sort(NP_N,NP_N+n2,cmp2);
	
	long long re = 0;
	
	for(int i=0;i<p1 && i<p2;i++){
		re+=NC_P[i]*NP_P[i];
	} 
	
	for(int i=0;i<n1 && i<n2;i++){
		re+=NC_N[i]*NP_N[i];
	}
	
	cout<<re<<endl;

	return 0;
}
