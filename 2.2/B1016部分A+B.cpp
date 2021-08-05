//B1016 ²¿·Ö×ÖA+B
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string Da,Db;
	int a,b;
	int re_a = 0,re_b = 0;
	cin>>Da>>a>>Db>>b;
	for(int i=0;i<Da.length();i++){
		if(Da[i] == a+'0'){
			re_a = 10*re_a + a;
		}
	}

	for(int i=0;i<Db.length();i++){
		if(Db[i] == b+'0'){
			re_b = 10*re_b + b;
		}
	}
	
	cout<<re_a+re_b;
	return 0;
} 
