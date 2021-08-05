//A1011 World Cup Betting
#include <iostream>
#include <map>
using namespace std;
int a[3];
double b[3];
map<int,char> mp;

int main(){

	mp[0] = 'W';
	mp[1] = 'T';
	mp[2] = 'L';
	for(int i=0;i<3;i++){
		double max = -1;
		double odd;
		for(int j=0;j<3;j++){
			cin>>odd;
			if(odd>max){
				a[i] = j;
				b[i] = odd;
				max = odd;
			}			
		}

	}
	for(int i=0;i<3;i++){
		cout<<mp[a[i]]<<" ";
	}

	double res = (b[0]*b[1]*b[2]*0.65-1)*2;
	printf("%.2f",res);
	return 0;
} 
