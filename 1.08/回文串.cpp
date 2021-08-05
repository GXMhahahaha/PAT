//pat b 1009 Ëµ·´»° 
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std; 
int main(){
	string a;
	getline(cin,a);
	reverse(a.begin(),a.end());
	string::iterator i=a.begin(),j=a.begin();
	for(;i!=a.end();i++){
		if((*i)==' '){
			reverse(j,i);
			j=i;
			j++;
		}
		if(i+1==a.end()){
			reverse(j,i+1);
		}
	}
//	reverse(j,i);
	cout<<a<<endl;
}
