//A1051 Pop Sequence
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;
const int maxn = 1010;
int arr[maxn];

int main(){
	int M,N,K;
	cin>>M>>N>>K;
	for(int i=0;i<K;i++){
		stack<int> s;
		for(int j=0;j<N;j++){
			int temp;
			scanf("%d",&temp);
			arr[j+1] = temp;
		}
		int cur = 1;					//´ý³öÕ»ÔªËØ 
		bool flag = true;
		
		for(int j=1;j<=N;j++){
			s.push(j);
			if(s.size()>M){
				flag = false;
				break;
			}
			
			while(!s.empty() && s.top() == arr[cur]){
				s.pop();
				cur++;
			}
		}
	
		if(s.empty() && flag == true){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	
	}
	

	
	
	return 0;
}
 
