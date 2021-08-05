#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	int num = 16848646;
	int n2 = 0;
	string test = "jauisodfgjhoiashdfoi";
	string str;
	stringstream ss;
	ss<<num<<"::"<<n2<<"72057/-*/*/*/::::"<<test;
	
	
	
	//str = ss.str();
	ss>>str;
	cout<<str<<endl;
	
	return 0;
} 
