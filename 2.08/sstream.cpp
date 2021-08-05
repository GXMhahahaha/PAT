#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string str = "15:69:63";
	stringstream ss;
	ss<<str;
	int a=0,b=0,c=0;
	
	sscanf(str.c_str(),"%d:%d:%d",&a,&b,&c);
	
//	ss>>a>>":">>b>>":">>c;
	cout<<a<<" "<<b<<" "<<c;
	
//	string o;
//	ss>>o;
//	cout<<o;
	return 0;
}
