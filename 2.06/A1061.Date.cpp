//A1061 Dating
#include <iostream>
#include <string>
#include <map>
using namespace std;

string str[4];
map<char,string> mp;
int hour[24];
int main(){
	mp['A'] = "MON";
	mp['B'] = "TUE";
	mp['C'] = "WED";
	mp['D'] = "THU";
	mp['E'] = "FRI";
	mp['F'] = "SAT";
	mp['G'] = "SUN";
	
	for(int i=0;i<24;i++){
		hour[i] = i;
	}
	
	for(int i=0;i<4;i++){
		cin>>str[i];
	}
	bool flag = 0;
	for(int i=0;i<str[0].length()&&i<str[1].length();i++){
		if(flag == 0 && str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G'){
			cout<<mp[str[0][i]]<<" ";
			flag = 1;
		}
		
		else if(flag == 1 && str[0][i] == str[1][i] && ((str[0][i] >= 'A' && str[0][i] <= 'N')||(str[0][i] >= '0' && str[0][i] <= '9'))){
			if(str[0][i] >= '0' && str[0][i] <= '9'){
				printf("%02d:",hour[str[0][i]-'0']);
			}
			else if(str[0][i] >= 'A' && str[0][i] <= 'N'){
				printf("%02d:",hour[str[0][i]-'A'+10]);
			}
			break;	
		}		 
	}
	
	for(int i=0;i<str[2].length()&&i<str[3].length();i++){
		if(str[2][i] == str[3][i] &&((str[2][i] >= 'A' && str[2][i] <= 'Z')||(str[2][i] >= 'a' && str[2][i] <= 'z'))){
			printf("%02d",i);
			break;
		}
	}
	
	return 0;
}
