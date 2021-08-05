//pat b 1009 说反话 二维数组解法 
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<string> s;  
int main(){
	string a;
	getline(cin,a);
	string temp;
	for(string::iterator it=a.begin();it!=a.end();it++){
		if((*it)!=' '){
			temp+=(*it);
		}
		if((*it)==' '||it+1==a.end()){
			s.push(temp);
			temp.clear();	
		}
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
		if(s.size()!=0)
			cout<<" ";
	}
	
}
