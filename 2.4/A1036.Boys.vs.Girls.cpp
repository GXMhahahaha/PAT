//A1046. Boys vs Girls
#include <iostream>
using namespace std;


int main(){
	int N;
	cin>>N;
	string boyname,boyid;
	string girlname,girlid;
	int max = -1;
	int min = 101;
	for(int i=0;i<N;i++){
		string name;
		char sex;
		string id;
		int grade;
		cin>>name>>sex>>id>>grade;
		if(sex == 'F'){
			if(grade > max){
				girlname = name;
				girlid = id;
				max = grade;
			}
		}
		else if(sex == 'M'){
			if(grade < min){
				boyname = name;
				boyid = id;
				min = grade;
			}
		}
	}
	
	if(girlname.length() == 0){
		cout<<"Absent"<<endl;
	}
	else if(girlname.length() != 0){
		cout<<girlname<<" "<<girlid<<endl;
	}
	
	if(boyname.length() == 0){
		cout<<"Absent"<<endl;
	}
	else if(boyname.length() != 0){
		cout<<boyname<<" "<<boyid<<endl;
	}
	if(girlname.length() == 0 || boyname.length() == 0){
		cout<<"NA"<<endl;
	}
	else{
		cout<<max-min<<endl;
	}
	return 0;
}
