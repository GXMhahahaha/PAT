//最长子列 递归 
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;

vector<int> list;
vector<int> dp; 
vector<int> re[maxn]; 

void Init(int counter){
	for(int i=0;i<counter;i++){
		dp.push_back(-1);
	}
}

int LIS_Pre(int pos){			//以pos为结尾的最长子列长度 
	if(pos == 0){
		dp[pos] = 1;
		if(re[0].empty()){
			re[0].push_back(list[0]);	
		}
		return 1;
	}
	
	if(dp[pos] != -1) 
		return dp[pos];
		
	else{
		bool flag = false;
		for(int i=0;i<pos;i++){
			if(list[i]<=list[pos] && dp[pos]<LIS_Pre(i)+1){    //勉强可以算是递归吧，似乎用迭代更容易些 
				dp[pos] = dp[i]+1;
				flag = true;
				re[pos] = re[i];
				re[pos].push_back(list[pos]);
			}
		}
		if(flag == false){
			dp[pos] = 1;
			re[pos].push_back(list[pos]);
		}
		return dp[pos]; 
	} 
}

int LIS(int len,int& poi){
	for(int i=0;i<len;i++){
		LIS_Pre(i);
	}
	int max = -1;
	for(int i=0;i<len;i++){
		if(dp[i] > max){
			max = dp[i];
			poi = i;
		}
	}
	
	return max;
} 

int main(){
	int counter = 0;
	do{
		int num;
		scanf("%d",&num);
		list.push_back(num);
		counter++;
	}while(getchar()!='\n');
	
	Init(counter);
	int poi = 0;
	cout<<LIS(counter,poi)<<endl;

	for(int i=0;i<re[poi].size();i++)
		cout<<re[poi][i]<<" ";
	


	return 0;
} 
