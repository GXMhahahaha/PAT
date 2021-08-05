#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
bool hashT[128] = {0};
string str;
string sub;
int main(){
	getline(cin,str);
	getline(cin,sub);

	for(int i=0;i<sub.length();i++){
		hashT[sub[i]] = 1;
	}
	for(int i=0;i<str.length();i++){
		if(hashT[str[i]] == 1){
			continue;
		}
		else{
			cout<<str[i];
		}
	}
	return 0;
}
