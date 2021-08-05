#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn];
int len[maxn];
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
	
	int maxlen = 1;	
	for(int i=0;i<N;i++){
		int up_most = N-i;
		if(maxlen > up_most){
			break;
		}
		int j = upper_bound(num,num+N,(long long)p*num[i])-num;					//这里需要强制类型转化 
		len[i] = j-i;
		if(len[i]>maxlen){
			maxlen = len[i];
		}
	}
	cout<<maxlen<<endl;
	return 0;
} 
