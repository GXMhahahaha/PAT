//B1028ÈË¿ÚÆÕ²é
#include <iostream>
#include <string>
using namespace std;
const int MIN = 18140906; 
const int MAX = 20140906; 

int main(){
	int N;
	cin>>N;
	string youngest,oldest;
	int min = 18140905;
	int max = 20140907;
	int eff = N;
	
	for(int i=0;i<N;i++){
		string name;
		string bir;
		cin>>name;
		int year,mon,date;
		scanf("%d/%d/%d",&year,&mon,&date);
		int birthday = year*1e4+mon*1e2+date;
			
		if(birthday>MAX || birthday<MIN){
			eff--;
			continue;
		}
		else{
			if(birthday>min){
				youngest = name;
				min = birthday;
			}
			if(birthday<max){
				oldest = name;
				max = birthday;
			}
		}
	}
	if(eff == 0){
		cout<<eff;
	}
	else{
		cout<<eff<<" "<<oldest<<" "<<youngest;	
	}

	
	return 0;
}
