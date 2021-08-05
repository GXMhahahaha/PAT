//B1004.≥…º®≈≈√˚
#include <iostream>
#include <string>
using namespace std;
struct STU{
	string name;
	string id;
};

int main(){
	int N;
	cin>>N; 
	int pos;
	int maxgrade = -1;
	int mingrade = 110;
	STU temp1,temp2;
	
	for(int i=0;i<N;i++){
		string _name,_id;
		int _grade;
		cin>>_name>>_id>>_grade;
		if(_grade>maxgrade){
			temp1.name = _name;
			temp1.id = _id;
			maxgrade = _grade;
		}
		if(_grade<mingrade){
			temp2.name = _name;
			temp2.id = _id;
			mingrade = _grade;
		}
	} 
	cout<<temp1.name<<" "<<temp1.id<<endl;
	cout<<temp2.name<<" "<<temp2.id<<endl;
		
	return 0;
} 
