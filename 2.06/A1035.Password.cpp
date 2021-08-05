#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'
const int maxn = 10010;
string nam[maxn],pass[maxn];
//vector<int> if_change;
int main(){
	int N;
	cin>>N;
	int change_num = 0;
	int pos = 0;
	for(int i=0;i<N;i++){
		string name,password;
		cin>>name>>password;
		bool change = false;		
		for(int j=0;j<password.length();j++){
			if(password[j] == '1'||password[j] == '0'||password[j] == 'l'||password[j] == 'O'){
				if(password[j] == '1'){
					password[j] = '@';
				}
				else if(password[j] == '0'){
					password[j] = '%';
				}
				else if(password[j] == 'l'){
					password[j] = 'L';
				}
				else if(password[j] == 'O'){
					password[j] = 'o';
				}
				change = true;				
			}

		}
		if(change == true){
			change_num++;
			nam[pos] = name;
			pass[pos] = password;
			pos++;
		}
		
	}
	if(change_num==0 && N==1){
		cout<<"There is 1 account and no account is modified"<<endl;
	}
	else if(change_num==0 && N>1){
		cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
	}
	else if(change_num>0){
		cout<<change_num<<endl;
		for(int i=0;i<change_num;i++){
			cout<<nam[i]<<" "<<pass[i]<<endl;
		}
	}
	
	return 0;
} 
