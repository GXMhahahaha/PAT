//vectorÕûÌåĞÔ²âÊÔ
#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> v1,v2;
	for(int i=0;i<10;i++){
		v1.push_back(i);
	}

	for(int i=0;i<10;i++){
		v2.push_back(i);
	}
	if(v1 == v2){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	} 
	
//	cout<<v1;
		
	return 0;
} 
