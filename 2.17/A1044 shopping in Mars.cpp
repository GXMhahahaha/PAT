//A1044 shopping in Mars 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn] = {0};
int sum[maxn] = {0};
int N,M;

struct Ans{
	int i;
	int j;
	int newsum;
};

vector<Ans> vi;

bool cmp(Ans a,Ans b){
	return a.i<b.i;
}

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
		sum[i]=sum[i-1]+num[i];
	}
	
	for(int i=1;i<=N;i++){
		int j = lower_bound(sum+i,sum+N+1,sum[i-1]+M)-sum;

		if(vi.size() == 0){
			Ans temp;
			temp.i = i;
			temp.j = j;
			temp.newsum = sum[j] - sum[i-1];
			vi.push_back(temp);
		}
		else if(sum[j] - sum[i-1] == vi[0].newsum){
			Ans temp;
			temp.i = i;
			temp.j = j;
			temp.newsum = sum[j] - sum[i-1];
			vi.push_back(temp);	
		}
		else if(sum[j] - sum[i-1] < vi[0].newsum && sum[j] - sum[i-1] >=0 ){
			vi.clear();
			Ans temp;
			temp.i = i;
			temp.j = j;
			temp.newsum = sum[j] - sum[i-1];
			vi.push_back(temp);
		}
	}

	sort(vi.begin(),vi.end(),cmp);
	for(int i=0;i<vi.size();i++){
		printf("%d-%d\n",vi[i].i,vi[i].j);
	}
	

	
	return 0;
}
