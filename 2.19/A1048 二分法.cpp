//A1048 ¶þ·Ö·¨ 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int num[maxn];

bool cmp(int a,int b){
	return a<b;
}
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	
	sort(num,num+N,cmp);
	for(int i=0;i<N;i++){
		int search = M-num[i];
		int j = lower_bound(num,num+N,search) - num;
		if(num[j] == search && i!=j){
			cout<<num[i]<<" "<<num[j]<<endl;
			return 0;
		}
	}
	cout<<"No Solution"<<endl;
	return 0;
} 
