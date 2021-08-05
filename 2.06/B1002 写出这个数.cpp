//B1002.写出这个数
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

stack<int> final;
map<int,string>mp;
int main(){
	mp[0] = "ling";
	mp[1] = "yi";
	mp[2] = "er";
	mp[3] = "san";
	mp[4] = "si";
	mp[5] = "wu";
	mp[6] = "liu";
	mp[7] = "qi";
	mp[8] = "ba";
	mp[9] = "jiu";
	
	string num;
	cin>>num;
	int sum = 0;
	for(int i=0;i<num.size();i++){
		sum+=num[i]-'0';
	}
	
	do{
		int temp;
		temp = sum%10;
		final.push(temp);
		sum/=10;
	}while(sum>0);
	
	while(!final.empty()){
		cout<<mp[final.top()];
		final.pop();
		if(final.size()>0){
			cout<<" ";
		}
	}	
	
	return 0;
} 
