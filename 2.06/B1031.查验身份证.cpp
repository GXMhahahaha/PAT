//B1031 查验身份证 
#include <iostream>
#include <string>

using namespace std;

bool isNum(char c){
	if(c=='0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
		return true;
	}
	else{
		return false;
	}
}
int wei[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char check[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main(){
	int N;
	cin>>N;
	bool flag = true;
	for(int i=0;i<N;i++){
		string str;
		cin>>str;
		int sum = 0;
		for(int i=0;i<17;i++){
			if(!isNum(str[i])){
				flag = false;
				cout<<str<<endl;
				break;
			}
			sum+=(str[i]-'0')*wei[i];
		}
		if(check[sum%11] != str[17]){
			flag = false;
			cout<<str<<endl;
		}
	}
	if(flag==true){
		cout<<"All passed"<<endl;
	}
	return 0;
} 
