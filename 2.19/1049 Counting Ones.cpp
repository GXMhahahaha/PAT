//1049 Counting Ones
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int right = 1;
	int ans = 0;
	for(int i=str.length()-1;i>=0;i--){
		string str_left = str.substr(0,i);
		int left = 0;
		sscanf(str_left.c_str(),"%d",&left);
		
		if(str[i] == '0'){
			ans += left*right;
		}
		else if(str[i]>'1' && str[i]<='9'){
			ans+= (left+1)*right;
		}
		else if(str[i]=='1'){
			ans+=left*right;
			int rr = 0;
			string str_right = str.substr(i+1);
			sscanf(str_right.c_str(),"%d",&rr);
			ans+=(rr+1);
		}
		right*=10;
	}
	cout<<ans<<endl;
	
	return 0;
} 
