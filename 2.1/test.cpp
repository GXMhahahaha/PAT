#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'
int N;
stack<int> s;
int Peek(){
	return 0;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		string cmd;
		//getline(cin,cmd);
		cin>>cmd;
		if(cmd=="Pop"){
			if(s.empty()){
				cout<<"Invalid"<<endl;
			}
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		else if(cmd=="PeekMedian"){
			cout<<Peek()<<endl;
		}
		else if(cmd=="Push"){
			int num;
			cin>>num;
			s.push(num);
			cout<<s.top()<<endl;
		}
	} 
	
	return 0;
}
