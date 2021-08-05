//A1024 Palindromic Number 
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

stack<int> temp;
vector<int> ans;

string Add(string ori,string rev){
	int carry = 0;
	for(int i=ori.length()-1;i>=0;i--){
		int mid = ori[i]-'0'+rev[i]-'0'+carry;
		temp.push(mid%10);
		carry = mid/10;
	}
	if(carry!=0){
		temp.push(carry);
	}
	ans.clear();
	while(!temp.empty()){
		ans.push_back(temp.top());
		temp.pop();
	}
	string ret;
	for(int i=0;i<ans.size();i++){
		ret+=ans[i]+'0';
	}

	return ret;
}

int main(){
	string N;
	int K;
	cin>>N>>K;
	string ori = N;
	reverse(N.begin(),N.end());				//N是逆转之后的数据； 
	if(N==ori){
		cout<<N<<endl<<"0"<<endl;
		return 0;
	}
	bool flag = false;
	int step = 0;
	string result = N;
	
	while(step < K){
		step++;
		result = Add(ori,result);
		ori = result;
		reverse(result.begin(),result.end());
		if(ori == result){
			break;
		}
	}
	
	cout<<ori<<endl<<step<<endl;

	return 0;
}
