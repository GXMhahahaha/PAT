//A1071 Speech Patterns
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<string,int> mp;
int main(){
	string str;
	getline(cin,str);
	
	int front = 0;
	int behind = 0;
	for(int i=0;i<str.length();i++){
		if(str[i] >='A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
	
	while(behind<str.length()){
		
		while(((str[behind] >='A' && str[behind] <= 'Z') || (str[behind] >='a' && str[behind] <= 'z') ||
		(str[behind] >='0' && str[behind] <= '9')) && behind<str.length()){
			behind++;
		}
		
		int len = behind-front;
		string temp = str.substr(front,len);
		if(mp.count(temp)==0){
			mp[temp] = 1;
		}
		else{
			mp[temp]++;
		}
		
		while(!((str[behind] >='A' && str[behind] <= 'Z') || (str[behind] >='a' && str[behind] <= 'z') ||
		(str[behind] >='0' && str[behind] <= '9')) && behind<str.length()){
			behind++;
		}
		front = behind;
	}
	int max = -1;
	string ans;
	for(map<string,int> :: iterator it = mp.begin();it!=mp.end();it++){
		if(it->second>max){
			max = it->second;
			ans = it->first; 
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
}
