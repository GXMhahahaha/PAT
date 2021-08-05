#include <stdio.h>
#include <iostream>
#include <deque>//Ë«¶Ë¶ÓÁÐ 
#include <string>
#include <vector> 
using namespace std;


int main(){
	deque<int> a;
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);	
//	vector<int> ::iterator it = a.begin();
	for(deque<int> ::iterator it = a.begin();it != a.end();it++){
		cout<<*(it)<<endl;
		
	//	printf("%x ",it);
	//	cout<<it<<endl;
	}
	return 0;
}
