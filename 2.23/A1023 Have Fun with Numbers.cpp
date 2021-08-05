//A1023 Have Fun with Numbers
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;
int HashT[10] = {0};

int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		HashT[str[i]-'0']++;
	}
	
	int carry = 0;
	for(int i=str.length()-1;i>=0;i--){
		int temp = (str[i]-'0')*2+carry;
		ans.push_back(temp%10);
		carry=temp/10;
	}
	
	if(carry!=0){
		ans.push_back(carry);
		cout<<"No"<<endl;

	}
	
	else{
		for(int i=0;i<ans.size();i++){
			HashT[ans[i]]--;
		}
	
		bool flag = true;
		for(int i=0;i<10;i++){
			if(HashT[i] != 0){
				cout<<"No"<<endl;
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout<<"Yes"<<endl;
		}
	}

	
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
