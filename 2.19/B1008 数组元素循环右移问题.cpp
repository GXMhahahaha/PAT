//B1008 ����Ԫ��ѭ���������� 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn];
int main(){
	int N,K;
	cin>>N>>K;
	K%=N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	reverse(a,a+(N-K));
	reverse(a+(N-K),a+N);
	reverse(a,a+N);
	for(int i=0;i<N;i++){
		cout<<a[i];
		if(i<N-1){
			cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}
