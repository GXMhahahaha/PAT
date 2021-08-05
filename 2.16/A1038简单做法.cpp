//A1038 Recover the Smallest Number
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
const int maxn = 10010;
string num[maxn];
string result;

bool cmp(string a,string b){
	return a+b<b+a;
	
	
}
	

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	sort(num,num+N,cmp);	

	for(int i=0;i<N;i++){
		result+=num[i];
	}

	while(result[0] == '0'){
		result.erase(result.begin());
	}
		
	if(result.length() == 0){
		cout<<"0";
	}
	else{
		cout<<result;
	}
	cout<<endl;
	
	return 0;
}
