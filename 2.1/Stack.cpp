#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'
int N;
stack<int> s;
const int maxn = 100010;
const int block_num = 317;			//分成317块 
const int num_with_a_block = 316;	//每块有316个数字
 
int table[maxn] = {0};
int block[block_num] = {0};			//每一块有几个数字 

int Search(int n){
	int count = 0;
	int i = 0;
	int result;
	int flag = false;
	while(flag == false){
		int temp = count+block[i];
		if(temp>=n){				//在第i块中 
			for(int j=i*num_with_a_block+1;j<(i+1)*num_with_a_block+1;j++){
				count+=table[j];
				if(count>=n){
					result = j;
					flag = true;
					break;
				}
			} 
		}
		else{
			count+=block[i];
			i++;
		}
	}
	return result;
}


int Peek(){
	int si_ze = s.size();
	if(si_ze%2 == 0){
		return Search(si_ze/2);
	}
	else{
		return Search((si_ze+1)/2);
	}
	 
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		string cmd;
		cin>>cmd;
		
		if(cmd=="Pop"){
			if(s.empty()){
				cout<<"Invalid"<<endl;
			}
			else{
				int tem = s.top();
				cout<<tem<<endl;
				table[tem]--;
				int pos = (tem-1)/num_with_a_block;
				block[pos]--;
				s.pop();
			}
		}
		else if(cmd=="PeekMedian"){
			
			if(s.empty()){
				cout<<"Invalid"<<endl;	
			}
			else{
				cout<<Peek()<<endl;				
			}

		}
		else if(cmd=="Push"){
			int num;
			cin>>num;
			s.push(num);
			table[num]++;
			int pos = (num-1)/num_with_a_block;			//第几块 
			block[pos]++;
		}
	} 
	
	return 0;
}
