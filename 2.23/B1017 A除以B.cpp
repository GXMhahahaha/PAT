//B1017 AГ§вдB
#include <iostream>
#include <stdio.h>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> ans;
int main(){
	string str;
	cin>>str;
	int div;
	cin>>div;
	int pre = 0;
	for(int i=0;i<str.length();){
		
		while(((str[i]-'0')+pre)/div == 0 && i<str.length()){
			ans.push_back(0);
			pre = 10*(pre+(str[i]-'0'));
			i++;
		}
		if(i<str.length()){
			ans.push_back(((str[i]-'0')+pre)/div);
			pre = 10*(((str[i]-'0')+pre)%div);
			i++;		
		}

	}
	int pos = 0;
	while(ans[pos] == 0 && pos<ans.size()){
		pos++;
	}
	
	if(pos == ans.size()){
		cout<<"0";
	}
	else{
		for(int i=pos;i<ans.size();i++){
		cout<<ans[i];
		}	
	}
	cout<<" ";
	cout<<pre/10;
	cout<<endl;
	return 0;
} 
