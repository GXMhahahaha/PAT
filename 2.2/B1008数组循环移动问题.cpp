//B1008 数组元素循环右移
#include <iostream>
using namespace std;
const int maxn = 100;
int a[maxn];
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int i=N-M%N;i<N;i++){
		cout<<a[i]<<" ";
	}
	for(int i=0;i<=N-M%N-1;i++){
		if(i<N-M%N-1)
		cout<<a[i]<<" ";
		else cout<<a[i];
	}
	return 0;
} 
