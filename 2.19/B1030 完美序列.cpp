//B1030 ÕÍ√¿–Ú¡–
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn];

bool cmp(int a,int b){
	return a<b;
}
int main(){
	int N,p;
	cin>>N>>p;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	
	sort(num,num+N,cmp);

	int maxlen = -1;
	for(int i=0,j=0;j<N;i++){
		int MIN = num[i];
		long long search = (long long)MIN*p;
		while(num[j]<=search && j<N){
			j++;
		}
		int len = j-i;
		if(len > maxlen){
			maxlen = len;
		}
	}
	cout<<maxlen<<endl;
	return 0;
} 
