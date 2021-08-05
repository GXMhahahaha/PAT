#include <iostream>
#include <string>

using namespace std;
string Sc_No;
struct NUM{
	string body;
	bool e_sign;			//0表示负，1表示正 
	int ex; 
}num;

int main(){
	cin>>Sc_No;
	if(Sc_No[0]=='-'){
		cout<<Sc_No[0];		
	}

	Sc_No.erase(Sc_No.begin());
	int i;
	
	for(i=Sc_No.length()-1;i>=0;i--){
		if(Sc_No[i] == 'E'){
			int j=i+1;
			if(Sc_No[j] == '+'){
				num.e_sign = 1;
			}
			else if(Sc_No[j] == '-'){
				num.e_sign = 0;
			}
			string :: iterator it = Sc_No.begin()+i;
			string temp;
			temp = Sc_No.substr(i+2);
			sscanf(temp.c_str(),"%d",&num.ex);
			Sc_No.erase(it,Sc_No.end());
			num.body = Sc_No;
			break; 
		}
	}

	if(num.e_sign == 0){
		cout<<"0.";
		for(int i=0;i<num.ex-1;i++){
			cout<<"0";
		}
		for(int i=0;i<num.body.size();i++){
			if(num.body[i]!='.'){
				cout<<num.body[i];
			}
		}
	}
	else if(num.e_sign == 1){
		int len = num.body.size()-2;
		if(len<=num.ex){
			int div = num.ex - len;
			for(int i=0;i<num.body.size();i++){
				if(num.body[i]!='.')
				cout<<num.body[i];
			}
			for(int i=0;i<div;i++){
				cout<<"0";
			}
		}
		else{
			num.body.erase(num.body.begin()+1);
			num.body.insert(num.body.begin()+num.ex+1,'.');
			cout<<num.body;
		}
	}
	return 0;
} 
