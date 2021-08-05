//A1011 ¿ìËÙÅÅĞò
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 0x7fffffff
using namespace std;
int N;
const int maxn = 100010;
int num[maxn];
int left_biggest[maxn];
int right_smallest[maxn];
vector<int> ans;
int main(){
	fill(left_biggest,left_biggest+maxn,-1);
	fill(right_smallest,right_smallest+maxn,INF);
	cin>>N; 
	int max = -1;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		if(num[i] > max){
			max = num[i];
		}
		left_biggest[i+1] = max;
	}
	int min = INF;
	for(int j=N-1;j>=1;j--){
		if(num[j] < min){
			min = num[j];
		}
		right_smallest[j-1] = min;
	}
	
	for(int i=0;i<N;i++){
		if(num[i]>left_biggest[i] && num[i]<right_smallest[i]){
			ans.push_back(num[i]);
		}
	}
	
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1){
			printf(" ");
		}
	}
	cout<<endl;
	return 0;
} 
