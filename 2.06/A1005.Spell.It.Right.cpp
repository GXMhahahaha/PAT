//A1005 Spell It Right
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,string> mp;
int main(){
	mp['0'] = "zero";
	mp['1'] = "one";
	mp['2'] = "two";
	mp['3'] = "three";
	mp['4'] = "four";
	mp['5'] = "five";
	mp['6'] = "six";
	mp['7'] = "seven";
	mp['8'] = "eight";
	mp['9'] = "nine";
	string num;
	cin>>num;
	int sum = 0;
	for(int i=0;i<num.size();i++){
	 	sum+=num[i]-'0';
	}
	char c[1000] = {'\0'};
	sprintf(c,"%d",sum);
	int i=0; 
	while(c[i]!='\0'){
		cout<<mp[c[i]];
		if(c[i+1]!='\0'){
			cout<<" ";
		}
		i++;
	}
	return 0;
}
