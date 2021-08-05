#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;

vector<int> list;
vector<int> dp; 
vector<int> re[maxn]; 

void Init(int counter){
	for(int i=0;i<counter;i++){
		dp.push_back(1);
	}
}

int LIS(int pos,int& whe){

	for(int i=0;i<=pos;i++){
		bool flag = false;
		for(int j=0;j<i;j++){
			if(list[i] >= list[j] && dp[i] < dp[j]+1){
				flag = true;
				dp[i] = dp[j]+1;
				re[i] = re[j];
				re[i].push_back(list[i]);
			}
		}
		
		if(flag == false){
			re[i].push_back(list[i]);
		}
		
	}
	
	int max = -1;
	for(int i=0;i<=pos;i++){
		if(dp[i] > max){
			max = dp[i];
			whe = i;
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
	int whe = 0;
	cout<<LIS(counter-1,whe)<<endl;
	
	for(int i=0;i<re[whe].size();i++){
		cout<<re[whe][i]<<" ";
	}
	return 0;
} 
