//B1028ÈË¿ÚÆÕ²é
#include <iostream>
#include <string>
using namespace std;
const int MIN = 18140906; 
const int MAX = 20140906; 

int main(){

		string name;
		string bir;
		cin>>name>>bir;
		for(int j=0;j<bir.length();j++){
			if(bir[j] == ':'){
				bir.erase(j);
			}
		}
		int birthday;
		sscanf(bir.c_str(),"%d",&birthday);
	cout<<birthday<<endl;
	cout<<bir;

	return 0;
}
